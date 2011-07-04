/* Universidade de Brasilia - UnB
*
*  -projeto: Karmonitomytty
*  -autor: Igor de Carvalho Coelho
*
*  -descrição: Este programa usa o serial do computador para implementar
* um protocolo de comunicação com uma fpga que inverte matrizes.
* O programa recebe a matriz e a envia a fpga usando a tecnica do goback-N
* para se certificar de que todos os numeros chegaram.
*/

//bibliotecas necessarias
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>	//controle de arquivos
#include <termios.h>	//uso do serial

#include "serial_comm.h"


int sh;			//descritor da conecção serial
char buffer[8];		//buffer circular para guardar o goback-N
char index1,index2;	//guarda em qual posição do buffer está a janela

//Função que inicia a conecção serial
//entradas:	(char *serial_dev) qual o dispositivo, ex: "/dev/ttyS0"
//		(int baudrate) velocidade do dispositivo, o padrão é 9600
//saida: erro = 0, sucesso = 1;
int init_serial(char *serial_dev, int baudrate){
	int bitrateflag;
	struct termios mytty;
	sh = open(serial_dev, O_RDWR | O_NDELAY);	//abre o arquivo que representa a conecção no modo escrita e leitura, o nodelay é para não bloquear
	if(sh == -1){
		printf("Erro: Não foi possivel abrir o arquivo da conecção %s\n",serial_dev);
		return 0;
	}
	if(tcgetattr(sh, &mytty)==-1){			//pega os atributos da conecção
		printf("Erro: Não foi possivel pegar os atributos da conecção serial\n");
		close(sh);
		return 0;
	}
	//Aqui setamos os atributos que queremos:
	/*
	flags de input(em ordem):
	converte a quebra de linha em um byte nulo
	desliga o processamento de input
	não marca erros de paridade e quebras
	não tira o bit mais significativo
	sem transiçao (cariage return)CR para (new line)NL
	ignora o (cariage return)CR
	sem transiçao (new line)NL para (cariage return)CR
	sem controle XON/XOFF
	*/
	mytty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP
		       |INLCR|IGNCR|ICRNL|IXON);
	/*
	flags de saida:
	sem processamento local de saida
	*/
	mytty.c_oflag &= ~OPOST;
	/*
	flags de processamento de linhas:
	sem echo
	sem echo para (new line)NL
	modo canoidal desligado
	sem caracteres de sinais
	sem processamento extendido de entrada
	*/
	mytty.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
	/*
	flags de processamento de caracteres:
	sem marcação para o tamanho do caractere
	sem teste de paridade
	forca o tamanho a ser 8bits
	*/
	mytty.c_cflag &= ~(CSIZE|PARENB);
	mytty.c_cflag |= CS8;
	switch(baudrate){	//seta a velocidade escolhida
		case 115200: bitrateflag=B115200; break;
		case 57600: bitrateflag=B57600; break;
		case 38400: bitrateflag=B38400; break;
		case 19200: bitrateflag=B19200; break;
		case 4800: bitrateflag=B4800; break;
		default: baudrate=9600; bitrateflag=B9600; break;
	}
	cfsetispeed(&mytty, bitrateflag);	//escreve a velociade de entrada
	cfsetospeed(&mytty, bitrateflag);	//escreve a velociade de saida
	if(tcsetattr(sh, TCSANOW, &mytty)==-1){	//escreve os atributos
		printf("Erro: não foi possivel escrever os atributos do dispositivo\n");
		close(sh);
		return 0;
 	}
	return 1;
}

/* Função responsavel por mandar n-bytes para a Serial
 * entrada:	(char *bytes) vetor com os bytes a serem enviados
 *		(int nbytes) numero de bytes a serem enviados
 * TODO: Implementar um retorno que indique sucesso ou que o dado nao foi enviado 
 */
int send_bytes(char *bytes, int nbytes){
	int ack;
	// fd_set descs;     //Handles de io
	// struct timeval timeout;
	//ack = write(sh, bytes, nbytes); //coloca os bytes no serial
	char teste[1] = {'a'};

	ack = write(sh, teste, 1); //coloca os bytes no serial

	printf("--->>> ACK: %d\n",ack);
	// O Codigo abaixo cria somente um tempo de sleep do programa
	// FD_ZERO(&descs);  // Inicializa a lista de handles
	// FD_SET(sh,  &descs);
	// timeout.tv_sec=5;
	// timeout.tv_usec=0;
	// select(FD_SETSIZE, &descs, NULL, NULL, &timeout);	//faz esperar para poder fazer outra operação no arquivo

	return ack;
}

/* Função responsavel pegar n-bytes da Serial
 * entrada:	(char *bytes) vetor para onde os bytes serão lidos
 *		(int nbytes) numero de bytes a serem lidos
 * saida:	numero de bytes lidos
 * 
 */
int receive_bytes(char *bytes, int nbytes){
	int n;
	n=read(sh,bytes, nbytes);
	return n;
}

/* 
 * Fecha a conexao serial. 
 * Todo verificar se a conexao ainda esta aberta
 * 
 */
void close_serial(){
	close(sh);
}


int main(void){
	if(init_serial("/dev/tty.PL2303-00001004", 115200)){
		if(send_bytes("aa", 2)) {
			char *lido;
			int nbytes = receive_bytes(lido, 2);

			printf("Foram lidos: %d\n", nbytes);
			return 1;
		}
	}
	return 0;
}

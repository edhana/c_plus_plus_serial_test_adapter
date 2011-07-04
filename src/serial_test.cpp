#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>  //controle de arquivos
#include <termios.h>  //uso do serial

 int fd; /* File descriptor for the port */

 /*  * 'open_port()' - Open serial port 1.
     *
     * Returns the file descriptor on success or -1 on error.
     */
int    open_port(void)
{
   printf("Trying to open port\n");

      fd = open("/dev/tty.PL2303-00001004", O_RDWR | O_NOCTTY | O_NDELAY);
      if (fd == -1)
      {
       /*
	* Could not open the port.
	*/
	perror("open_port: Unable to open /dev/ttyUSB0 - ");
      }
      else
      {
	fcntl(fd, F_SETFL, 0);
        printf("I opened the port /dev/ttyUSB0  !\n");

        struct termios options;

       /*
       * Get the current options for the port...
       */
       tcgetattr(fd, &options);

     /*
     * Set the baud rates to 57600 ..
     */
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

     /*
     * Enable the receiver and set local mode...
     */
    options.c_cflag |= (CLOCAL | CREAD);

     // 8N1
     options.c_cflag &= ~PARENB;
     options.c_cflag &= ~CSTOPB;
     options.c_cflag &= ~CSIZE; /* Mask the character size bits */
     options.c_cflag |= CS8;    /* Select 8 data bits */


      // Do the following to enable hardware flow control:
     //    options.c_cflag |= CNEW_RTSCTS;    /* Also called RTSCTS /

     //Similarly, to disable hardware flow control:
    //options.c_cflag &= ~CNEW_RTSCTS;


     /*
     * Set the new options for the port...
     */
    tcsetattr(fd, TCSANOW, &options);


      }
      return (fd);
}



int main(int argc, char *argv[])
{

   open_port();
   int n = write(fd, "aa", 2);
   if (n < 0)   fputs("write() of 2 bytes failed!\n", stderr);

   printf("Wrote \%i bytes\n",n);

    char *buffer;
   //fcntl(fd, F_SETFL, FNDELAY);
   int recieved =   read( fd, buffer, 2);
 printf("recieved \%i bytes\n",recieved);
     close(fd);

     return EXIT_SUCCESS;
}
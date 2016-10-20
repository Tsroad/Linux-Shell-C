// @authors Keung Charteris & T.s.road CZQ
// @version 1.0 ($Revision$)
// @date 18/10/2016 $LastChangedDate$
// @addr. GUET, Gui Lin, 540001,  P.R.China
// @contact : cztsiang@gmail.com &  t.s.road@bk.ru
// @date Copyright(c)  2016-2020,  All rights reserved.
//  This is an open access code distributed under the Creative Commons Attribution License, which permits 
//  unrestricted use, distribution, and reproduction in any medium, provided the original work is properly cited. 

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t my_read(int fd, void *buf, size_t length) 
{ 
	ssize_t done = length; 

	while(done > 0) { 
		done = read(fd, buf, length); 
		
		if(done != length) 
			if(errno == EINTR) 
				done = length; 
			else{
				perror("fail to read"); 
				return -1; 
			}
		else
			break;
	} 

	return done; 
}

ssize_t my_write(int fd, void *buf, size_t length) 
{ 
	ssize_t done = length;

	while(done > 0) { 
		done = write(fd, buf, length);

		if(done != length) 
			if(errno == EINTR) 
				done = length; 
			else{
				perror("fail to write"); 
				return -1; 
			}
		else
			break;
	} 

	return done;
}

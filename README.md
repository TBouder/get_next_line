# get_next_line

[PDF](https://mega.nz/#!VxAWmZSa!mD6758M1O06xHDIL-loe0mCVd6_R179JIar4kGiVA68)

###Gameplay  
>The get_next_line() function stores a string ended by \n or EOF from the file descriptor FD. Each call to this function will read one line until the end
of the file.
>The function returns 1 if something was read, 0 if nothing was read and -1 if an error occurs (bad file descriptor or bad storing parameters LINE).

###Bonus :  
- [x] Possibility to read multiples FD and to keep our position in each file  
- [x] Only one static variable used  

###Requirements :
- [LIBFT](https://bitbucket.org/Tbouder/libft)
- C compiler  
- GNU  

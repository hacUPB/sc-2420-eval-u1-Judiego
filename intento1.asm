@272
        D=A
        @cont2
        M=D
        @16384
        D=A
        @punt
        M=D
(LOOP2)
        @32
        D=A
        @cont
        M=D

        
        AMD=-1
        @numero
        M=D

(LOOP)
        @numero
        D=M
        @punt
        A=M
        M=D
        @punt
        M=M+1
        @cont
        MD=M-1
        @LOOP
        D;JGT

        @32
        D=A
        @SumaBucle
        MD=D
        @punt
        M=D+M
        @cont2
        MD=M-1
        
        @LOOP2
        D;JGT


        @272
        D=A
        @cont3
        M=D
        @16415
        D=A
        @punt
        M=D
(LOOP4)
        @30
        D=A
        @cont
        M=D

        
        AMD=-1
        @numero
        M=D

(LOOP3)
        @numero
        D=M
        @punt
        A=M
        M=D
        @punt
        M=M+1
        @cont
        MD=M-1
        @LOOP3
        D;JGT

        @30
        D=A
        @SumaBucle
        MD=D
        @punt
        M=D+M
        @cont3
        MD=M-1
        
        @LOOP4
        D;JGT


(END)
        @END
        0;JMP
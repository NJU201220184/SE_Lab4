objects = main.o File_generator.o Input_generator.o Code_Processor.o 
text = A.out A_error.log A_out.txt B.out B_error.log B_out.txt input.txt temp.cpp
demo : $(objects)                                                   
		g++ -o demo $(objects)                                        

main.o : main.cpp main.h                                       
		g++ -c main.cpp  

File_generator.o : File_generator.cpp File_generator.h                                       
		g++ -c File_generator.cpp  

Input_generator.o : Input_generator.cpp Input_generator.h                                       
		g++ -c Input_generator.cpp    

Code_Processor.o : Code_Processor.cpp Code_Processor.h                                       
		g++ -c Code_Processor.cpp                                             
                                                  
.CEN : clean
clean :                                                                  
		rm demo  $(objects) $(text)

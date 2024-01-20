from ast import main
import re


#Aqui es donde se crean las expresiones regulares para cada variable y operacion del EBNF
#primero estan todas las variables que no tuvieran recursion

Digito= r"[1-9]"
Digito_o_zero= fr"[{Digito}|0]"
entero= r"[1-9]+[0-9]*"
variable= r"^[A-Za-z][A-Za-z0-9]*"
booleano= r"^true|false$"
string= r"#[A-Za-z0-9]+#"
espacio= r"{\s}+"
tipo= r"(int|bool|str)"
declaracion= rf"{tipo}\s+{variable}\s*;"
operaciones= r"[-+*/<=]+"
puntuaciones= r"([()\[\]{};,.:])+"
caracteres= (entero + r"|"+ variable + r"|" + string + r"|"+ booleano + r"|"+ operaciones + r"|" + puntuaciones) 
oper_bin = r"("+ entero +r"|" + booleano + r"|" + string + r"|" + variable +r")"+ operaciones+r"("+ entero +r"|"+ booleano+ r"|"+ string +r"|"+ variable +r")"
igual = variable + r"[=]{1}"+ r"operador_check" + r"[;]"
cond=r"("+ entero +r"|" + booleano + r"|" + string + r"|" + variable +r")"+r"[<==]+"+r"("+ entero +r"|"+ booleano+ r"|"+ string +r"|"+ variable +r")"


oper_bin_pat=re.compile(oper_bin)
igual_pat=re.compile(igual)
condi_pat=re.compile(cond)
Digito_pat=re.compile(Digito)
Digito_o_zero_pat=re.compile(Digito_o_zero)
entero_pat=re.compile(entero)
variable_pat=re.compile(variable)
booleano_pat=re.compile(booleano)
string_pat=re.compile(string)
operaciones_pat=re.compile(operaciones)
punt_pat=re.compile(puntuaciones)



'''
check_oper_bin(caract)
———————
caract: lista 
————————
Esta funcion recibe una lista vacia que lee y revisa el operador binario, haciendo uso de parentesis ()
Si el operador binario esta correcto retorna True, en caso contrario retorna False  '''

def check_oper_bin(caract): 
    pilapos=[]
    i=0
    while i <len(caract):
        if caract[i]=="(":
            pilapos.append(i)
        if caract[i]==")":
            caract[pilapos[-1]:i]
            if oper_bin_pat.search("".join(caract[pilapos[-1]+1:i])):
                caract[pilapos[-1]:i+1]=["1"]*len(caract[pilapos[-1]:i])
                print(caract) 
                pilapos.pop()    
        i+=1 
    if oper_bin_pat.search("".join(caract[1:-1])):
        return True
    else:
        return False  
    

            


'''chequear_condicion(condition)
———————–
Condition : lista
————————
funcion que recibe una lista vacia que recorre, lee y revisa la condicion, usando su patron y siguiendo una logica similar a
la funcion check_oper_bin 
La funcion chequear_condicion devuelve True si la expresion de igualdad esta correcta, en caso contrario retorna False'''
def chequear_condicion(condition):
    pila=[]
    posicion=[]
    cont=0
    text=""
    if condition[0]!="(":
        condition.insert(0,"(")
        condition.insert(len(condition,")"))
    
    while cont<len(condition):
        pila.append(condition[cont])
        if condition[cont]=="(":
            posicion.append(cont)
        
        elif condition[cont]==")":
            for elemento in pila[posicion[-1]:(cont+1)]:
                text+=str(elemento)

            if (condi_pat.search(text)):
                del pila[posicion[-1]:(cont+2)]
                for caracter in text:
                    pila.append(1)
            else:
                return False
            text=""
            posicion.pop()
        cont=cont+1    

    return True




'''
check_igual(texto)
———————
texto: lista 
————————
Funcion que recibe una lista vacia que recorre, lee y revisa la igualdad, buscando desde un = hasta un ; 
Esta funcion toma todo lo que se encuentra entre esos caracteres y llama la funcion check_oper_bin, que lo reemplaza
por un 1 si esta devuelve true, esto es para decir que el operador que se encuentra entremedio esta correcta
La funcion chequear_condicion devuelve True si la expresion de igualdad esta correcta, en caso contrario retorna False '''
def check_igual(texto):
   cont=0
   inicio_op_bin=0
   fin_op_bin=0
   while inicio_op_bin< len(texto):
    if texto[cont]=="=":
        inicio_op_bin=cont+1
    elif texto[cont]==";":
        fin_op_bin=cont
    
    if check_oper_bin(texto[inicio_op_bin:fin_op_bin]) and inicio_op_bin!=0 and fin_op_bin!=0:
        texto[inicio_op_bin:fin_op_bin]=["operador_check"]
        if igual.search("".join(texto)):
            return True

    return False






'''formato(c,codigo,cantEspacios,cantSaltosdelinea,cantTab)
———————
c: int
codigo: lista
cantEspacios: int
cantSaltosLinea: int 
tabsStack: int
cantTab: int
f: texto
————————
Funcion que lee el codigo y le va agregando los tab, espacios, saltos de linea que correspondan  '''

def formato(c,codigo,cantEspacios,cantSaltosLinea,tabsStack,cantTab,f):
    while c<len(codigo):
        if Digito_o_zero_pat.search(codigo[c]) or entero_pat.search(codigo[c]) or punt_pat.search(codigo[c]) or codigo[c]==")" or string_pat.search(codigo[c]):
            f.write(codigo[c])
            f.write(" "*cantEspacios)

        elif variable_pat.search(codigo[c]) and codigo[c] != "int"and codigo[c] !="str"and codigo[c] !="bool"and not string_pat.search(codigo[c]):
            if codigo[c-1] == "int" or codigo[c-1] == "str" or codigo[c-1] == "bool" or codigo[c-1] == "(" or variable_pat.search(codigo[c-1]) :
                f.write(codigo[c])
                f.write(" "*cantEspacios)
            else:
                f.write('\t'*cantTab*tabsStack)
                f.write(codigo[c])
                f.write(" "*cantEspacios)  
        
        elif codigo[c] == "int" or codigo[c] == "str" or codigo[c] == "bool":
            f.write('\t'*cantTab*tabsStack)
            f.write(codigo[c])
            f.write(" "*cantEspacios)
        
        elif codigo[c] == ";":
            f.write(codigo[c])
            f.write('\n'*cantSaltosLinea)


        elif codigo[c] == "{":
            line = formato(line)
        elif codigo[c] ==  "main":
            f.write(codigo[c])
        elif codigo[c] == "(" :
            if codigo[c-1] == "main":
                f.write(codigo[c])
            else:
                f.write(codigo[c])
                f.write(" "*cantEspacios)

        elif codigo[c] == "}":
            return c
           
        c+=1
    return len(codigo)    



print(formato(3,"codigo.txt",4))























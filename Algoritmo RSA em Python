# Importei "randint" da biblioteca "random"
# Será usado para obter valores aleatórios para P e Q
from random import randint

# Usei a função "randint" para gerar valores aleatórios para P e Q entre 0 e 100
p = randint(0, 100)
q = randint(0, 100)

# Função para verificar se um número é primo
# Usarei para verificar se P e Q são primos. 
def Primo(numero):
    # Se for 2, retorna verdadeiro
    if(numero == 2):
        return True
    # Se for menor que 2 ou divisível por 2, retorna falso
    elif((numero < 2) or ((numero % 2) == 0)):
        return False
    # Se for maior que 2, o algoritmo verificará se o número é divisível por todos os números menores que ele (até 2). Se NÃO for, retorna falso
    elif(numero > 2):
        for i in range(2, numero):
            if not(numero % i):
                return False
    # Se não está incluído em nenhum dos casos acima, retorna verdadeiro.
    return True

# Criei duas variáveis para guardar o resultado da checagem acima.

PrimoP = Primo(p)
PrimoQ = Primo(q)

# Enquanto P e Q não forem ambos primos, o algoritmo trocará seus valores repetidamente.
while(((PrimoP == False) or (PrimoQ == False))):
    p = randint(0, 100)
    q = randint(0, 100)
    PrimoP = Primo(p)
    PrimoQ = Primo(q)

print("Bem-vindo ao Algoritmo de Criptografia RSA!\n")

# O algoritmo então mostrará os valores encontrados
print("Os valores de P e Q, gerados aleatoriamente, são:", p, "e", q)
 
# Cálculo do n
n = p * q
print("\nCalculando o n:", p, "*", q, "=", n)

# Cálculo de z
z = (p-1)*(q-1)
print("Calculando o z:", p-1, "*", q-1, "=", z)

# Função para o cálculo de máximo divisor comum. 
# Será útil para encontrar o valor de 'e', que deve ser um primo próximo de Z
def MDCe(e, z):
    while(z != 0):
        e, z = z, e % z
    return e

# Algoritmo euclidiano extendido
# Será útil para fazer o cálculo do inverso multiplicativo
def eea(a,b):
    if(a % b == 0):
        return(b, 0, 1)
    else:
        mdc,s,t = eea(b,a%b)
        s = s -((a//b) * t)
        return(mdc,t,s)
 
# Inverso multiplicativo
def inverso(e,r):
    mdc,s,_=eea(e,r)
    return s % r
    
# Cálculo do valor de e
# O algoritmo verificará o máximo divisor comum entre Z e uma série de números de 1 a 1000, a fim de descobrir um número relativamente primo a Z.
for i in range(1, 1000):
    if(MDCe(i,z) == 1):
        e=i
print("\nO valor de e é:", e)


# Cálculo do inverso multiplicativo de E e Z
d = inverso(e,z)
print("O valor de d é: ", d)


publica = (e,n)
privada = (d,n)
print("\nA chave pública é:", publica)
print("A chave privada é:", privada)
 
#Função para transformar as mensagens em ASCII

def criptografar(chave_publi,mensagem):
    e,n=chave_publi
    # x é a lista que guardará a mensagem criptografada
    x=[]
    m=0
    for i in mensagem:
        #As condições trarão valores diferentes para maiúsculas, minúsculas e espaço.
        if(i.isupper()):
            # A função ord pegará o unicode da letra
            m = ord(i)-65
            c=(m**e)%n
            # A letra criptografada será incluida na lista
            x.append(c)
        elif(i.islower()):               
            m= ord(i)-97
            c=(m**e)%n
            x.append(c)
        elif(i.isspace()):
            x.append(400)
    return x
     
#Função para descriptografar as mensagens
def descriptografar(chave_priv,mensagemc):
    d,n=chave_priv
    txt=mensagemc.split(',')
    x=''
    m=0
    for i in txt:
        if(i=='400'):
            x+=' '
        else:
            m=(int(i)**d)%n
            m+=65
            c=chr(m)
            x+=c
    return x

opcao = input("\nDigite 1 para criptografar uma mensagem ou 2 para descriptografá-la: ")

if (opcao == '1'):

  mensagem = input("Digite sua mensagem: ")
  msg = criptografar(publica, mensagem)
  print("Sua mensagem criptografada é:", msg)

  descrip = input("\nDeseja descriptografá-la? (digite 1 para sim ou 2 para não) ")
  if (descrip == '1'):
    mensagem = input("\nDigite a mensagem criptografada (separe os números com uma vírgula ','): ")
    msg = descriptografar(privada, mensagem)
    print("Sua mensagem descriptografada é:", msg)
  elif (descrip == '1'):
    print("Obrigado por usar o programa! :)")
  else:
    print("Opção inválida :(")

elif (opcao == '2'):
  mensagem = input("Digite a mensagem criptografada (separe os números com uma vírgula ','): ")
  msg = descriptografar(privada, mensagem)
  print("Sua mensagem descriptografada é:", msg)
else:
  print("Opção inválida :(")

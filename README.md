# Exemplos Capítulo 3
Integrantes: Ana Paula Bruno Carbone (9761805) Fernando d'Avila Axthelm (9778881)

# Ambiente utilizado
 O ambiente utilizado para a implementação dos exemplos é a distribuição Debian 32bits, versão 9.4.0-i386-netinst para o kernel i386, do sistema operacional Linux rodando em uma máquina virtual Virtual Box versão 5.2.8 r121009 (Qt5.6.2), utilizando-se de 2,048MB de memória RAM. Além disso, a máquina host possui um processador i7 7700K, entretanto, a máquina virtual está limitada a um núcleo do processador.
 Os códigos fontes estarão disponíveis na plataforma GitHub através do link:

# Comandos utilizados para compilação e execução
 Inicialmente, após configurada e inicializada a máquina, abriu-se uma janela de terminal e nos autenticamos como super-usuário (su) para realizar as atualizações do sistema operacional e instalar o compilador que será utilizado nos testes. Por meio dos comandos: apt-get update e apt-get install build-essential.  A biblioteca instalada, build-essential, conta com compilador gcc e o g++ versão 6.3.0.
 O comando utilizado para compilação é: gcc nomeProgama.c -o nomeProgama.out. Este comando compila o arquivo em c e escreve o resultado da compilação em um novo arquivo.
 Já o comando para a execução é: ./nomePrograma.out

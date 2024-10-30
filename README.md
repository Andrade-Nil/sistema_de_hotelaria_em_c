# Sistema de Gerenciamento de Hotel

Este é um sistema de gerenciamento de hotel, permitindo o cadastro de hóspedes, reservas e locações de quartos.

## Funcionalidades

- Cadastro de hóspedes
- Adição de reservas
- Listagem de locações
- Verificação de disponibilidade de quartos

## Pré-requisitos

Antes de executar o sistema, você precisará preparar seu ambiente. Siga as instruções abaixo de acordo com o seu sistema operacional.

### Ubuntu / Debian

1. **Atualize o sistema**:
   ```bash
   sudo apt update
   sudo apt upgrade

2. **Atualize o sistema**:
sudo apt install build-essential


3. **Verifique se o GCC está instalado**:
gcc --version



## macOS
1. **Instale o Xcode Command Line Tools**:
xcode-select --install

3. **Verifique se o GCC está instalado**:
gcc --version

## Windows
1. **Instale o MinGW**:
- Baixe o MinGW aqui.
- Durante a instalação, certifique-se de incluir o mingw32-base e o mingw32-gcc-g++.
2. **dicione o MinGW ao PATH**:

- Vá até as Configurações do sistema, acesse Sistema -> Configurações avançadas do sistema -> Variáveis de ambiente.
- Na seção Variáveis do sistema, encontre a variável Path, selecione-a e clique em Editar.
- Adicione o caminho para a pasta bin do MinGW (por exemplo, C:\MinGW\bin).
3. **Verifique se o GCC está instalado**:
gcc --version



### Compilação
1. **Clone o repositório:**:
git clone https://seu-repositorio.git
cd seu-repositorio

2. **Compile o projeto**:
make

### Execução
./hotel_sistem   # Para Linux e macOS
hotel_sistem.exe   # Para Windows


### caso de atualizações
gcc -D_XOPEN_SOURCE=700 -I../include -o hotel_system main.c reserva.c quarto.c hospede.c locacao.c relatorios.c alertas.c util.c

gcc -o hotel_system main.c reserva.c quarto.c hospede.c locacao.c relatorios.c alertas.c util.c

./hotel_system


### Personalização

- **Clone o repositório**: Atualize o link do repositório com o URL correto do seu projeto.
- **Licença**: Se estiver utilizando uma licença diferente, atualize essa seção.
- **Contribuição**: Você pode adicionar mais informações sobre como contribuir, se necessário.

Com essas informações, os usuários do seu sistema terão um guia completo sobre como preparar o ambiente para a execução do software. Se precisar de mais detalhes ou ajustes, é só avisar!



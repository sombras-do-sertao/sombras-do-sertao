# 🌵 Sombras do Sertão

Sombras do Sertão é um jogo de pixel art inspirado no estilo retrô, que te leva ao coração do cangaço, uma época em que destemidos fora-da-lei, conhecidos como cangaceiros, vagavam pelas áridas paisagens do Nordeste do Brasil. Com batalhas intensas, jogabilidade estratégica e uma rica história, por terrenos perigosos, evitando a polícia e derrotando gangues rivais.

## 📜 História

Ambientado no início do século XX, você é o integrante de um grupo de cangaceiros, viajando pelo sertão árido e impiedoso. Com seu bando ao lado, você enfrentará inimigos ferozes, gangues rivais e forças opressoras.

## 💻 Tecnologias Utilizadas

Sombras do Sertão utiliza a biblioteca Allegro 5, uma poderosa API de desenvolvimento de jogos 2D em C. Ela oferece suporte para gráficos, entrada de usuário, áudio, timers e muito mais. O Allegro é ideal para jogos retrô devido à sua simplicidade e eficiência. Para mais informações, visite o [site oficial](https://liballeg.org/).

## 📹 Gameplay

![Sombras do Sertão - Gameplay](assets/video/gameplay.gif)

## 🎮 Como Jogar

### 🪟 Windows
1. **Instale a biblioteca GCC/MinGW**: Para compilar o código-fonte do jogo, você precisará de um compilador compatível com C. Recomendamos o GCC/MinGW, que é um conjunto de ferramentas para desenvolvimento de software em C/C++ para Windows. Você pode baixá-lo [aqui](https://sourceforge.net/projects/mingw/).
2. **Clone o repositório**: Clone este repositório para o seu ambiente local.
3. **Compile o jogo**: Temos um script de compilação pronto para uso. Execute o arquivo `scripts/compiler.bat` para compilar o código-fonte. O arquivo executavel gerado estará localizado na pasta `bin`.
4. **Execute o jogo**: Para executar o jogo você pode passar a flag `--run` para executar o jogo automaticamente após a compilação ou clicar duas vezes no arquivo `Sombras do Sertão.bat` na raiz do projeto.

> **Nota**: Para ocorrer tudo certo na compilação, é necessário que o compilador GCC/MinGW esteja adicionado ao PATH do sistema. E também ao chamar o script de compilação deve estar na raiz do projeto.

---

### 🐧 Linux
1. **use o script de instalação**: Para instalar as dependências do jogo, execute o script `scripts/setup.sh`. Este script instalará as dependências necessárias para compilar o jogo.
2. **Compile o jogo**: Temos um script de compilação pronto para uso. Execute o arquivo `scripts/compiler.sh` para compilar o código-fonte. O arquivo binario gerado estará localizado na pasta `bin`.
3. **Execute o jogo**: Para executar o jogo você pode passar a flag `--run` para executar o jogo automaticamente após a compilação ou clicar duas vezes no arquivo `SombrasDoSertao` na pasta `bin`.

## 📖 Tutorial

### Como Jogar

1. **Movimentação**: Use as teclas de seta ou `W`, `A`, `S`, `D` para mover o protagonista.
2. **Atirar**: Pressione a tecla `espaço` para atirar.
3. **Facada**: Pressione a tecla `F` para dar uma facada.
5. **Pausar**: Pressione a tecla `ESC` para pausar o jogo e acessar o menu.
6. **Selecionar Opção**: Use o `enter` para acessar as fases.

### Objetivos do Jogo

- **Sobreviver**: Evite os inimigos e mantenha sua saúde.
- **Colete Itens**: Pegue munição e kits médicos para se manter no jogo.
- **Complete as Fases**: Progrida através das fases derrotando inimigos.

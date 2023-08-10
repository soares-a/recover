# Recover

## Recuperação de Imagens JPEG de Imagem Forense

Este é um programa simples em C que recupera imagens JPEG de uma imagem forense. Ele lê um arquivo de imagem forense e identifica as assinaturas JPEG dentro do arquivo para extrair e salvar as imagens JPEG individuais.

## Uso

Compile o programa usando um compilador C (por exemplo, o GCC) e forneça o arquivo de imagem forense como argumento de linha de comando ao executar o executável.

`
gcc -o recover recover.c`

`./recover imagem_forense.raw`

Substitua `imagem_forense.raw` pelo nome real do arquivo de imagem forense que você deseja processar.

## Descrição
O programa percorre a imagem forense em blocos de 512 bytes. Ele identifica as assinaturas das imagens JPEG e as extrai em arquivos JPEG separados, nomeando-os como 001.jpg, 002.jpg e assim por diante.

O programa garante que fecha corretamente cada arquivo JPEG antes de abrir um novo. Ele lida com casos em que a imagem forense não pode ser aberta ou onde a alocação de memória falha.

## Requisitos
Compilador C (por exemplo, GCC)

## Referências 
CS50 Library: https://cs50.harvard.edu/x/2023/library/

CS50 - Introduction to Computer Science course: https://cs50.harvard.edu/x/2023/

This program was developed as part of the CS50 - Introduction to Computer Science course at Harvard University.

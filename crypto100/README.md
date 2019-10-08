# Hot Dog time!

### Descrição
```
César resolveu pedir um hot dog completão com tudo que tem direito 
dentro (inclusive vinagrete). Depois de exatos 64 minutos, o lanche 
chegou todo ao contrário, parecia até que tinha sido revirado umas 5 vezes! Mas não 
tinha nem como reclamar também, custou apenas 1 REAL. 
Ele deixou a seguinte mensagem de avaliação:

KcTOxAzSIV1NLFkM0Q1UOBFWZdFN

O pessoal do restaurante não entendeu nada... será que você consegue desvendar?

Flag: SECCOM-2019{xxx}
```
**Pontuação**: 100

**Dica**: Tudo está na descrição. Vinagrete vem antes de César.

**Dica (anunciada)**: https://www.dcode.fr/en

**Dica (anunciada) 2**: ANTES DE TODAS AS CIFRAS ROBUSTAS QUE TEMOS HOJE, EXISTIU UM TEMPO ONDE EXISTIAM AS CONHECIDAS CIFRAS CLÁSSICAS

### Write-up

Temos diversas pistas pela descrição, começando com "64 minutos", que com o formato da mensagem remete a Base64.

Executando o decode, chegamos em um conteúdo que não é texto. Porém, como a descrição diz que "o lanche chegou todo ao contrário", vamos começar invertendo a mensagem antes do decode.

```sh
$ echo "KcTOxAzSIV1NLFkM0Q1UOBFWZdFN" | rev | base64 -D
4WYXPNST42AK7UHK0197
```
Agora que temos um conteúdo em texto, parece algum tipo de cifra simples. Usando a descrição, provavelmente o texto está cifrado usando Vigenere e Caesar.

Se tudo está presente na descrição, a chave do algoritmo de Vigenere também deve estar. Logo de cara, a primeira coisa que chama atenção é que o texto resultante contém números e letras maiúsculas apenas, e que a palavra `REAL` está presente na descrição totalmente em letras maiúsculas, e nada além dessa palavra está da mesma forma.

Utilizando o [dcode.fr](https://www.dcode.fr/vigenere-cipher) com o alfabeto de letras maiúsculas e números, e a palavra `REAL` como chave, obtemos o seguinte resultado:

```
Vigenere  REAL
(Alphabet (36) ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789)
NSYM8JSINYA9QQH9JX9W
```

Como a descrição sugere que Caesar também está envolvido, podemos pegar esse resultado e aplicar no algoritmo de Caesar, utilizando um alfabeto customizado. O texto ainda sugere que o hot dog "parecia até que tinha sido revirado umas 5 vezes", então tentando um decrypt com 5 rotações, obtemos a flag:

```
Caesar Cipher - Shift by 5
FGHIJKLMNOPQRSTUVWXYZ0123456789ABCDE
ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
INTH3ENDIT54LLC4ES4R
```
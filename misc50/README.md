# Bem-vindos!

### Descrição
```
Todos os desafios possuem dicas, que tem um custo fixo de 50 pontos. Que tal começar com o pé direito hein?
```
**Pontuação**: 50

**Dica (anunciada)**: https://lmgtfy.com/?q=string+with+%3D%3D+at+the+end

### Write-up
O desafio contém uma imagem chamada `welcome.png`, que tem o seguinte contéudo
![alt text](welcome.png "welcome.png image content")

Fazendo um decode de Base64 no conteúdo da imagem, obtemos a flag:

```sh
echo U0VDQ09NLTIwMTl7UXUzXzA1X0owZ29zX0NvbTNjM219Cg== | base64 -d
SECCOM-2019{Qu3_05_J0gos_Com3c3m}
```
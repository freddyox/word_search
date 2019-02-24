# Word Search Generator and Game
* A fully functional word search game.
* About 300 words are randomly selected from a dictionary of over 300k words. From here, I randomly choose words based on string length which allows me to adjust the game difficulty, *e.g.* I can choose more smaller-words (words with a smaller length) making the game more difficult for the user.
* The game is built using the <a href="https://www.sfml-dev.org/">SFML multimedia library</a> which means everything has been built from scratch, including the word search board, all user interactions which includes mouse events, sprite movements (the check/unchecked box), and dynamically built colors to make finding words easier for the user. The program includes sounds as well!
* I had a lot of fun building this project! For example, placing many words on a grid is an interesting programming problem. Additionally, a user must click and drag the mouse across cells in order to *select* a word which introduces another interesting programming challenge; this word must be correct too, otherwise the program outputs an obnoxious noise to signal failure.
* The "cheat" button highlights all words to find.
* A description of the program may be found <a href="https://freddyox.github.io/blog/word-search/">here</a>, but here is an example:

![WS](https://github.com/freddyox/freddyox.github.io/blob/master/images/word_search/word_search_thumbnail.png)

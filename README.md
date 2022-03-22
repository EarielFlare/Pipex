# Pipex
Pipex project for School42.

#### Проект состоит из основной (mandatory) и бонусной (bonus) частей.  
Команда **make** (**make all**) соберет основную, **make bonus** - бонусную часть.  
Название исполняемого файла при любом варианте компиляции - **pipex**.

> #### Пример работы pipex с двумя командами (mandatory):
**./pipex infile "cmd1 -arg" "cmd2 -arg" outfile**  
(аналогично **< infile cmd1 -arg | cmd2 -arg > outfile**)
> #### Пример работы pipex с двумя и более командами (bonus):
**./pipex infile "cmd1 -arg" "cmd2 -arg" "cmd3 -arg" outfile**  
(аналогично **< infile cmd1 -arg | cmd2 -arg | cmd3 -arg > outfile**)
> #### Пример работы pipex с функцией here_doc (bonus):
**./pipex here_doc LIMITER "cmd1 -arg" "cmd2 -arg" "cmd3 -arg" outfile**  
(аналогично **cmd1 -arg << LIMITER | cmd2 -arg | cmd3 -arg >> outfile**)

#### В работе были использованы следующие источники:
https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901 - статья  
https://github.com/tolmvad/pipex/blob/master/Makefile - был разобран этот код  
учебник Head First C (Изучаем Си): A Brain-Friendly Guide (2012) - главы 9, 10.

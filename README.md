<!-- PROJECT LOGO -->
<br />
<div align="center">

  <h1 align="center">my_42sh</h1>
  <h3 align="center">A better homemade shell</h3>

</div>

<!-- TABLE OF CONTENTS -->
<details>
    <summary>Table of Contents</summary>
    <ol>
        <li>
            <a href="#about-the-project">About The Project</a>
        </li>
        <li>
            <a href="#content-of-the-project">Content of the project</a>
            <ul>
                <li><a href="#main-features">Main features</a></li>
            </ul>
        </li>
        <li>
            <a href="#getting-started">Getting Started</a>
        </li>
    </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

This project is a reimplementation of one of the of the tree first-year Epitech's final project.  
The goal was to recreate a Unix Shell (the reference shell was TCSH).  
I really liked this project so in my spare time i'm recreating it with my new knowledge.  
I'm still fairly new to system programming, so probably a lot of my code could be improved so don't be afraid to make suggestions !  

## Content of the project
This project is still a work in progress, and a lot of the features listed below have already been implemented in my previous project, but i'm trying to reimplement them in a better way  
(If you wish to check the project on wich this one is based, check this [repository](https://github.com/iMeaNz/42sh))
### Main features
- Spaces and tabulations ❌
- $PATH and environnement handling ❌
- Errors and return value ❌
- Redirections ('<', '<<', '>' '<<') ❌
- Pipes ('|') ❌
- Builtins functions : cd, echo, exit, setenv and unsetenv ❌
- Separators (';', '&&', '||') ❌
- Inhibitors ('\') ❌
- Globbings ('*', '?', '[]' '{}') ❌
- Job control ('&', fg) ❌
- Backticks ('``') ❌
- Parentheses ❌
- Variables (local and env) ❌
- Special variables (term, precmd, cwdcmd, ignoreof...) ❌
- History ('!') ❌
- Aliases ❌
- Line edition ✅
- Auto-completion ❌
- Scripting ❌

## Getting started
1. Clone the repository
  ```sh
  git clone git@github.com:iMeaNz/42sh.git
  ```
2. Compile the program
  ```sh
  make
  ```
3. Run the program
  ```sh
  ./42sh
  ```
# IQuizt
Quiz application made by students, using Qt.

# Developers:  
Ambrus-Dobai Márton  
Berta Gábor Pál  
Orbán András Kende  
Szauer Bertalan  

# Download  
- **Linux**
  - Download latest release zip.
  - Unzip.
  - Get these packages, if you don't have them:
    - build-essential
    - qt5-default (5.12)
  - Add execution property to the IQuizt binary.
  - Run it (can test with included quizzes).
  - If problem occurred try running it from the terminal.
- **Windows**
  - Download latest windows release zip.
  - Unzip.
  - Run the executable (can test with included quizzes).
- **MacOS**
  - Work in progress!

# Build
- Ubuntu:
  - Get packages:  
    > cmake  
    > make  
    > gcc  
    > qt5-default  
  - Run ubuntu_build.sh
  - Tested on Ubuntu 20.04.2 LTS

# How It Works  
### When you open the application you can see the main menu.  
![Alt text](assets/pics/menu.png?raw=true "menu.png")  
### Firstly you shold set your own proflie in this app. Click on **create my profile**.   
![Alt text](assets/pics/profile.png?raw=true "profile.png")  
Type your name.  
![Alt text](assets/pics/profile2.png?raw=true "profile2.png")  
When your profile is created you will see this.   
![Alt text](assets/pics/profile3.png?raw=true "profile3.png")   
When you have set your profile you can then check your stats. Such as your level, correct answers and  worong answers.  
![Alt text](assets/pics/profile4.png?raw=true "profile4.png")  
### Secondly you should set the directory ,in which your quizzes are kept.You only need to do this once because from then the app will find the quizzes in that folder.   
![Alt text](assets/pics/set.png?raw=true "set.png")  
If you click on load existing quizzes you can load all the quizzes from your folder. If you click on a quiz from the list ,then you can work on that quiz.  
![Alt text](assets/pics/load.png?raw=true "load.png") ![Alt text](assets/pics/click.png?raw=true "click.png")  
If you have chosen a quiz, you can then edit and fill it out.  
![Alt text](assets/pics/fill.png?raw=true "fill.png")  
### This is how a quiz will look if you choose to fill it out.  
![Alt text](assets/pics/fill2.png?raw=true "fill2.png")     
This is how a quiz looks once you answered a question.The results update after each question.  
![Alt text](assets/pics/fill3.png?raw=true "fill3.png")   
### You can also edit a quiz.You can add and remove questions.  
![Alt text](assets/pics/edit.png?raw=true "edit.png")  
When you click add ,then an empty question appears.  
![Alt text](assets/pics/edit2.png?raw=true "edit2.png")  
If you make any changes you have to click save.  
![Alt text](assets/pics/save.png?raw=true "save.png")  
When you edit a quiz you can then fill it out.  
![Alt text](assets/pics/edit3.png?raw=true "edit3.png") ![Alt text](assets/pics/fill4.png?raw=true "fill4.png")

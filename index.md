ㅤ
# Authentication_System
## SNHU CS-499 2021

# Self Assesment

This project involves the refinment of the final project for the class IT-145. This project was the creation of a zoo authentication system for a hypethetial zoo. This was done in java and was made up of a login screen which would allow the entering of a username and password. If the username/password combination was correct, the system would then display one of three text pages related to the user account type.
More information can be found in the code review below. 



# Code Review

The first step to enhancing this project was performing a code review.


[![Watch the video](https://img.youtube.com/vi/2QkOakAuvMk/maxresdefault.jpg)](https://youtu.be/2QkOakAuvMk)
<a id="raw-url" href="https://media.githubusercontent.com/media/flywheel11/flywheel11.github.io/master/Zoo Authentication System Code Review.mp4">Download Video</a>

# Artifact Narritive

Name: Zoo Authentication System \n
Assignment: 7-1 Final Project \n
Origin: IT-145 \n
This artifact will be used for all three categories of the final project. This project was initially created as an authentication system for a zoo for the final project for IT-145 in 2018. It was written in Java and would allow the user to log in to an account stored on a credentials file as plain text. The system would hash the password given by the user using MD5 and compare that hash to the hash stored on the credentials file associated with a username. The system would then authenticate the user and display a data file with data related to the user's account type (zookeeper, admin, or veterinarian), or the system would reject the login attempt up to three times and finally quit the program after a third failed attempt.
 
## Artifact Inclusion
I chose this artifact because of its potential to showcase my skills and because it seemed like an exciting and challenging project. When creating an authentication system, it is essential that the code is written with security best practices in mind, and coding within those constraints seemed to make for an excellent showcase for the skills I have developed over these four years. Ever since that original project, it always bothered me that I had left it unfinished, and being able to revisit the project and refine it seemed too good to pass up. 
 
 
#### Software Design and Engineering
I was able to enhance this project in several ways within this category. First, the original project was written in Java, but porting it over to C++ would simplify its integration into C++ projects. As such, I transferred the project into C++. Next, I expanded the project's complexity by adding a registration screen that can register new admins and users. In the new system, users can register a new account with a new username and password combination as long as the same username does not currently exist in the database. If a new admin wishes to register, the system requires that an existing admin login. Finally, I improved the software by patching several security holes. For example, a return statement in the user class existed that would return all stored credentials to anywhere in the program. In addition to this, the file that contains the main class has been streamlined and no longer handles any credentials, and variables that store any passwords are immediately cleared from memory after they are no longer needed. 
 
#### Algorithms and Data Structures
For this category, I was able to enhance the complexity and the security of the project. Previously, the zoo authentication system stored passwords hashed with the MD5 digest algorithm and would compare the old hash to a new hash of a password the user supplies when logging in. This algorithm is considered does not hold up to modern cryptographic standards, and so I replaced it with the industry-standard SHA-256 hashing algorithm. I also employed algorithmic password salting, which enhances the security of password hashes by adding randomness to passwords to ensure that no two users have the same password hash. This improvement prevents two kinds of attacks. It prevents a rainbow table attack in which a hacker has a table of known password hashes, and it protects user passwords in the event of an unauthorized database entry.
 
#### Databases
For this section, I enhanced the artifact by essentially turning it into a full-stack application. I created an interface between C++ and MongoDB which allows for the creation and reading of stored account credentials. This interface allows for the reading of previously created accounts to log in and the creation of new entries so that new users can register an account with a new username, account type, password hash, and password salt. This completed program basically amounts to a full-stack application where the MongoDB database acts as a back-end, the C++ program acts as a mid-level, and the console acts as the front-end. This system would be ideal for authenticating users within an office or campus with a central MongoDB server.
 
 
## Objectives
All the planned functional enhancements for all three categories have been implemented. All that remains is the refining of the program and the addition of supplemental documentation, including a readme file, additional comments, a library dependencies list, and additional installation instructions.
 
#### Design and Engineering
All the planned enhancements for this section have been implemented. The original program was rewritten in C++ from Java. The program was also written as a general authentication system rather than an authentication system specific to a zoo. A registration screen was also added, allowing users to register an admin account or a user account. As described, to register an admin account, a current admin must log in first. 

#### Algorithms and Data structures
All the planned enhancements for this section have been implemented. First, the original MD5 password hashing algorithm was replaced with the industry-standard SHA-256 hashing algorithm. Next, password salting was implemented to obscure the password hashes. These passwords salts are stored with the password hashes in the database. Finally, the ability to interact with information from the database was added, allowing the program to create new documents and read existing documents. This feature allows the user to log in as an existing user and register new accounts.
           
#### Databases
All the planned enhancements for this section have been implemented. MongoDB database was created to store account credentials. This database was run on a Docker image and can connect to the program on port localhost:27017. The ability to write and read from the database was also implemented. Each account document consists of an id, username, account type, password hash, and password salt, all of which can be read and written to by the program.
 
## Process Reflection
Design and Engineering
While developing this section of the artifact, I ran into very few issues. I went through the old project and started recreating the logic in C++. I also added some new classes, including the registration, login, and CRUD classes. Creating and using classes in C++ compared to Java was a little more complex than I anticipated, but after reading some documentation on classes and header files, the process went smoothly.
One of the big things I learned was that Java is a lot more secure of a language than I had previously assumed. With Java, there are several built-in security features, such as its built-in cryptographic functions, that I had taken for granted when recreating this project in C++. Because of this, I needed to find an external library with the desired cryptographic features. 
 
#### Algorithms and Data structures
I also ran into few problems when implementing the features from this section into the project. I did have some problems with a library I was using for hashing passwords. I previously used the CryptoPP library for the SHA-256 hashing algorithm and other features, including binary to hexadecimal conversion. However, it conflicted with the Mongocxx driver I needed, so I switched to a header-only library called hash-library for this functionality. The salt was easy enough to generate. To accomplish this, I created a random string of alphanumeric characters, which I then hashed to add more randomness and convert it to hexadecimal with "hash-library."
 
#### Databases
This section was challenging to implement the planned features. One of the main issues I ran up against was setting up the API between visual C++ and MongoDB. MongoDB created an official API, but the setup had been quite tricky. There are were lots of little pieces to set up, and each one was running into issues. For example, the MongoDB C++ Driver required the Libmongoc library to be installed on my system, but I kept running into issues. The main problem was a lack of available documentation. Without solid documentation, getting the libraries set up turned into an arduous process. Other than that, though, actually writing the interface between MongoDB and C++ was reasonably straightforward. I was able to set up the database with Docker and exposed it to port 27017. I then connected to it with a URL and was able to interact with it from my program.


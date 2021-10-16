ㅤ
# Authentication_System
# SNHU CS-499 2021
This project involves the refinment of the final project for the class IT-145. This project originally started as a zoo authentication system for a hypethetial zoo. This was done in java and was made up of a login screen which would allow the entering of a username and password. If the username/password combination was correct, the system would then display one of three text pages related to the user account type.
More information can be found in the code review below. 

## Self Assesment

### Program Reflection
Hello, world!
My name is Christopher George, and this is my e-portfolio for the SNHU computer science capstone, CS-499. Over the course of the SNHU computer science program, I have learned more about and have become more accomplished at developing software than I could have imagined at the start of this academic adventure. One of the areas I have improved the most is collaborating on team projects using version control software such as Git, GitHub, and Bitbucket. Collaboration skills were essential during the class CS-310, Collaboration and Team Projects. During this class, the students collaborated on a jukebox application that would list the songs in a playlist that each student created. I also gained experience reviewing other students' committed code and approving commits. It's hard to believe that at one point, I didn't use git for projects and that now it is an indispensable part of my workflow. 

Another skill I learned that will come in handy on the business side of things was how to communicate with clients and an Agile team. During the class CS-250 Software Development Cycle, I was able to refine my communication skills by assuming the various roles of an Agile team, which included the role of the product owner. The product owner was an exciting role to take on because they facilitate communication with the team and the stakeholders and represent the best interest of the stakeholders or client. This role posed an exciting challenge because the product owner acts almost as a negotiator for the stakeholders, and so has to understand what the stakeholder's best interest is and try and determine what is realistic for the team to do.

Another essential skill that I learned during this program was problem-solving with fundamental concepts, such as data structure and algorithms. This skill was beneficial for the class CS-260 Algorithms and Data Structures. In this class, I used several robust data structures, such as linked lists, binary trees, and hash tables. I was also able to implement the sorting algorithms quick sort and selection sort. This implementation was not the easiest but working in C++ for the first time was a new and exciting challenge.

Out of all the skills I learned, though, the one area I seemed to excel at the most was in full-stack development. I demonstrated this skill in multiple classes, including CS-465 Full Stack Development I, CS-470 Full Stack Development II, CS-340 Client Server Development, IT-270 Web Site Design, and a few other classes. I learned everything from front-end design to back-end server management to creating and connecting REST APIs during these classes. In the class CS-470 Full Stack Development II, I was even able to create a full-stack application of the cloud using AWS. To do this, I used several AWS services, including lambda, S3, and EC2. Through these classes, I demonstrated my ability with software engineering, along with the creation and use of databases. During this class, security was explicitly addressed. In it, I learned about creating policies and roles for AWS using their IAM service. To set roles and policies for specific services, I used a JSON file with the proper permissions as content.

### Project Introduction

For this portfolio, I chose one project to demonstrate my software design and engineering abilities, algorithms and data structures, and databases. As such, I decided to enhance a project from the class IT-145 Found in App Development. The initial project was the creation of a zoo authentication system created in Java. This authentication system was a simple project that would allow a user to type in a username and password that would then log the user in. This project was perfect for this portfolio because of its opportunity for improvement. Some of its flaws include major security holes (see code review below), the lack of a method for registering a new user, the storage of credentials in a text file, and its insecure MD5 password hashing algorithm. By fixing these flaws and adding to the project's complexity further, I can demonstrate my capabilities in several computer science facets in addition to the ones listed above, including secure coding and the use of well-founded programming techniques.


## Code Review

The first step to enhancing this project was performing a code review.


[![Watch the video](https://img.youtube.com/vi/2QkOakAuvMk/maxresdefault.jpg)](https://youtu.be/2QkOakAuvMk)
<a id="raw-url" href="https://github.com/flywheel11/flywheel11.github.io/raw/master/Zoo%20Authentication%20System%20Code%20Review.mp4">Download Video</a>

## Artifact Narritive

##### Name: Zoo Authentication System <br />
##### Assignment: 7-1 Final Project <br />
##### Origin: IT-145 <br />
This project was initially created as an authentication system for a zoo for the final project for IT-145 in 2018. It was written in Java and would allow the user to log in to an account stored on a credentials file as plain text. The system would hash the password given by the user using MD5 and compare that hash to the hash stored on the credentials file associated with a username. The system would then authenticate the user and display a data file with data related to the user's account type (zookeeper, admin, or veterinarian), or the system would reject the login attempt up to three times and finally quit the program after a third failed attempt.
 
### Artifact Inclusion
I created this project as an authentication system for a zoo for the final project for IT-145 in 2018. It was written in Java and would allow the user to log in to an account stored on a credentials file as plain text. The system would hash the password given by the user using MD5 and compare that hash to the hash stored on the credentials file associated with a username. The system would then authenticate the user and display a data file with data related to the user's account type (zookeeper, admin, or veterinarian), or the system would reject the login attempt up to three times and finally quit the program after a third failed attempt.

 
##### Software Design and Engineering
I was able to enhance this project in several ways within this category. First, I transferred the project into C++; the original project was written in Java, but porting it over to C++ would simplify its integration into C++ projects. Next, I expanded the project's complexity by adding a registration screen to register new admins and users. The implementation of this can be seen below.
![Register User](https://raw.githubusercontent.com/flywheel11/flywheel11.github.io/master/Pictures/newUser%Register.png)
In the new system, users can register a new account with a unique username and password combination as long as the same username does not currently exist in the database. If a new admin wishes to register, the system requires an existing admin login, as can be seen below.
![Register Admin](https://raw.githubusercontent.com/flywheel11/flywheel11.github.io/master/Pictures/newAdmin2%Succesful%Registration.png)
The error seen in the example above was caused by a user being added to the existing database.
Finally, I improved the software by patching several security holes. For example, a return statement in the user class existed that would return all stored credentials to anywhere in the program. In addition to this, the file that contains the main class has been streamlined and no longer handles any credentials, and variables that store any passwords are immediately cleared from memory after they are no longer needed. 

 
##### Algorithms and Data Structures
For this category, I was able to enhance the complexity and the security of the project. Previously, the zoo authentication system stored passwords hashed with the MD5 digest algorithm and would compare the old hash to a new hash of a password the user supplies when logging in. This algorithm is considered obsolete and does not hold up to modern cryptographic standards, so I replaced it with the industry-standard SHA-256 hashing algorithm. I also employed algorithmic password salting, which enhances the security of password hashes by adding randomness to passwords to ensure that no two users have the same password hash. This improvement prevents two kinds of attacks. It prevents a rainbow table attack in which a hacker has a table of known password hashes, and it protects user passwords in the event of an unauthorized database entry.
 
##### Databases
For this section, I enhanced the artifact by essentially turning it into a full-stack application. I created an interface between C++ and MongoDB which allows for the creation and reading of stored account credentials. This interface allows for the reading of previously created accounts to log in and the creation of new entries so that new users can register an account with a new username, account type, password hash, and password salt. This completed program basically amounts to a full-stack application where the MongoDB database acts as a back-end, the C++ program serves as a mid-level, and the console acts as the front-end. This system would be ideal for authenticating users within an office or campus with a central MongoDB server. I also created a MongoDB database that holds user credentials and account information, such as account type (user or admin). The database design and schema can be seen in the following diagram;
![Database Diagram](https://raw.githubusercontent.com/flywheel11/flywheel11.github.io/master/Pictures/DB%diagram.png)
 
 
### Objectives

##### Design and Engineering
The original program was rewritten in C++ from Java. The program was also written as a general authentication system rather than an authentication system specific to a zoo. A registration screen was also added, allowing users to register an admin account or a user account. As described, to register an admin account, a current admin must log in first. 

##### Algorithms and Data structures
First, the original MD5 password hashing algorithm was replaced with the industry-standard SHA-256 hashing algorithm. Next, password salting was implemented to obscure the password hashes. These password salts are stored with the password hashes in the database. Finally, the ability to interact with information from the database was added, allowing the program to create new documents and read existing documents. This feature enables the user to log in as an existing user and register new accounts.
           
##### Databases
A MongoDB database was created to store account credentials. This database was run on a Docker image and can connect to the program on port localhost:27017. The ability to write and read from the database was also implemented. Each account document consists of an id, username, account type, password hash, and password salt, all of which can be read and written to by the program. A test entry to the database can be seen below.
![User in database](https://raw.githubusercontent.com/flywheel11/flywheel11.github.io/master/Pictures/newUser%UserDatabase.png)

 
### Process Reflection
##### Design and Engineering
While developing this section of the artifact, I ran into very few issues. I went through the old project and started recreating the logic in C++. I also added some new classes, including the registration, login, and CRUD classes. Creating and using classes in C++ compared to Java was a little more complex than I anticipated, but after reading some documentation on classes and header files, the process went smoothly.
One of the big things I learned was that Java is a lot more secure of a language than I had previously assumed. With Java, there are several built-in security features, such as its built-in cryptographic functions, that I had taken for granted when recreating this project in C++. Because of this, I needed to find an external library with the desired cryptographic features. 
 
##### Algorithms and Data structures
I also ran into few problems when implementing the features from this section into the project. I did have some problems with a library I was using for hashing passwords. I previously used the CryptoPP library for the SHA-256 hashing algorithm and other features, including binary to hexadecimal conversion. However, it conflicted with the Mongocxx driver I needed, so I switched to a header-only library called hash-library for this functionality. The salt was easy enough to generate. To accomplish this, I created a random string of alphanumeric characters, which I then hashed to add more randomness and convert it to hexadecimal with "hash-library."
 
##### Databases
This section was challenging to implement the planned features. One of the main issues I ran up against was setting up the API between visual C++ and MongoDB. MongoDB created an official API, but the setup had been quite tricky. There are were lots of little pieces to set up, and each one was running into issues. For example, the MongoDB C++ Driver required the Libmongoc library to be installed on my system, but I kept running into issues. The main problem was a lack of available documentation. Without solid documentation, getting the libraries set up turned into an arduous process. Other than that, though, actually writing the interface between MongoDB and C++ was reasonably straightforward. I was able to set up the database with Docker and exposed it to port 27017. I then connected to it with a URL and was able to interact with it from my program.

## Links
Here are some links to the project and some other files.

Original artifact: <a id="raw-url" href="https://github.com/flywheel11/flywheel11.github.io/tree/master/IT-145_%20ZooAthenticationSystem_Original_Project">Link</a><br>
Enhanced Artifact: <a id="raw-url" href="https://github.com/flywheel11/flywheel11.github.io/tree/master/CS-499%20Final%20Authentication_System%20Enhanced%20Project">Link</a><br>
MongoDB Database tar with test data: <a id="raw-url" href="https://github.com/flywheel11/flywheel11.github.io/tree/master/Docker%20images">Link</a><br>
Additional Pictures of the enhanced project: <a id="raw-url" href="https://github.com/flywheel11/flywheel11.github.io/tree/master/Pictures">Link</a><br>
You Tube code review: <a id="raw-url" href="https://www.youtube.com/watch?v=2QkOakAuvMk">Link</a><br>
Code review download: <a id="raw-url" href="https://github.com/flywheel11/flywheel11.github.io/raw/master/Zoo%20Authentication%20System%20Code%20Review.mp4">Link</a><br>
Link to this e-portfolio: <a id="raw-url" href="https://flywheel11.github.io/">Link</a><br>

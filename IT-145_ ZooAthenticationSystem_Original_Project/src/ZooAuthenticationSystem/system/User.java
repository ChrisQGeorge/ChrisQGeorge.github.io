/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ZooAuthenticationSystem.system;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;
/**
 *
 * @author owner
 */
public class User {
    //defines object fields
    private String UserName;
    private String PassHash;
    private String PassWord;
    private String UserType;
    
    //finds the credential file and converts it to a string
    private String getCredString()throws IOException {
    FileInputStream credFileStream = null;
    Scanner credTXT = null;
    String credentialString = "";
    
    credFileStream = new FileInputStream("./src/Resources/credentials.txt");
    credTXT = new Scanner(credFileStream);
    
    //appends credentailString with credential file data, line by line
    while (credTXT.hasNextLine()) {
       credentialString = credentialString + credTXT.nextLine() + "\n";
    }
    
    //closes file and returns file data in the form of a string
    credFileStream.close();
    return credentialString;
    }
    
    //checks user name in credentials file with user input
    private String userNameChecker(String credString, String userInput) {
        Scanner credScan = new Scanner(credString);
        String credWord = "";
        String credLine = "";
        
        //checks credential data to see if it contains userInput
        while(credScan.hasNext()){
            credWord = credScan.next();
            //returns proper line if userInput was found in credSting and returns line or null if not found
            if(credWord.equals(userInput)) {
                
                credLine = credLine + credWord;
                credLine = credLine + " " + credScan.nextLine();

                return credLine;
            } else {
                    credScan.nextLine();
            }
        }
        return "null";
    }
    
    //tries to populate the object if username is found or send null if not found
    public String populateObject(String userInput)throws IOException{
        Scanner credLine = null;
        Scanner credLineCheck = null;
        int credLineLength = 0;
        String credString = getCredString();
        String password = "";
        
        //either sends "q" or "null" back if user name not found or "found" if it is found
        if (userInput.equals("q")) {
            return "q";
        } else if (userNameChecker(credString, userInput).equals("null")) {
            return "null";
            //populates object if user name found and returns "found"
        } else {
            credLine = new Scanner(userNameChecker(credString, userInput));
            credLineCheck = new Scanner(userNameChecker(credString, userInput));
            while (credLineCheck.hasNext()){
                credLineLength ++;
                credLineCheck.next();
            }
            //populates object variables
            this.UserName = credLine.next();
            this.PassHash = credLine.next();
           
            for (int i = (credLineLength - 3); i > 0; i --) {
                password = password + credLine.next() + " ";
            }
            this.PassWord = password;
            this.UserType = credLine.next();
            return "found";
        }
        
    }
    
    //checks password hash with password hash on record and returns "found" if they are the same or a "null" if not
    public String checkPass(String userInput) throws Exception {
        MD5Digest MD5 = new MD5Digest();
        String userInputHash = "";
        
        //hashes user input
        userInputHash = MD5.passwordHash(userInput);
        
        //checks user hash against user has on record and returns a the confirmation "found" or "null"
        if (userInput.equals("q")) {
            return "q";
        } else if (userInputHash.equals(PassHash)){
            return "found";
        } else {
            return "null";
        }
    }
    
    //displays data depending on type of user
    public void getData() throws Exception {
        FileInputStream dataFileStream = null;
        Scanner dataTXT = null;
        String dataString = "null";
        
        //gets data from file depending on user type
        if (UserType.equals("admin")) {
            dataFileStream = new FileInputStream("./src/Resources/Data/admin.txt");
            
        } else if (UserType.equals("zookeeper")){
            dataFileStream = new FileInputStream("./src/Resources/Data/zookeeper.txt");
            
        } else if (UserType.equals("veterinarian")){
            dataFileStream = new FileInputStream("./src/Resources/Data/veterinarian.txt");
        } else {
            return;
        }
        
        dataTXT = new Scanner(dataFileStream);
        
        //converts data file to string
        dataString = "";
        while (dataTXT.hasNextLine()) {
           dataString = dataString + dataTXT.nextLine() + "\n";
        }
        
        //prints data string
        System.out.println(dataString);
        
        
        dataFileStream.close();
        
    }
    
    //sets object variables to default
    public void eraseData() {
        //sets all object variables to default
        this.UserName = null;
        this.PassHash = null;
        this.PassWord = null;
        this.UserType = null;
    }
}


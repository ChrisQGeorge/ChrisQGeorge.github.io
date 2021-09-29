package ZooAuthenticationSystem.system;

import java.util.Scanner;
import java.io.IOException;
import java.util.concurrent.TimeUnit;

public class ZooAuthenticationSystem {
    
    //gets user name from user and verifies that the user name exists in the system
    public static String getUserName(User currentUser)throws IOException{
        Scanner scnr = new Scanner(System.in);
        String userInput = "";
        String confirmationString = "";
        
        //this loop allows the user to exit the program or enter new user name
        while(!confirmationString.equals("q")) {
            //prompts user for user name
           System.out.println("Please enter username or \"q\" to exit program.");
           userInput = scnr.nextLine();
           
           //populates currentUser object and checks if user name is in the system
           confirmationString = currentUser.populateObject(userInput);
           
           /*if user name is in the system and the user did not exit, this if 
           statement sends a confirmation to main to proceed. If the user name 
           is not found, it restarts the loop and prompts the user for a 
           different user name. If the user chooses to quit, it sends that to
           main and does so.
           */
           if ((!confirmationString.equals("q")) && ((!confirmationString.equals("null")))) {
               return confirmationString;
           }
           if (confirmationString.equals("null")) {
               System.out.println("Unkown command or username.");
           }
        }
        return confirmationString;
        
        
    }
    
    //gets password from user and verifies that the password is correct
    public static String getUserPassword(User currentUser) throws Exception {
        Scanner scnr = new Scanner(System.in);
        String userInput = "";
        String confirmationString = "";
        int passwordAttempts = 0;
        
        //this loop allows the user to quit or enter new password
        while(!confirmationString.equals("q")) {
            
            /*exits the program if there are too many failed password attempts by 
            sending an exit string to main.
            */
            if (passwordAttempts > 2) {
               confirmationString = "q";
               return confirmationString;
                       
           }
            //prompts user for password
           System.out.println("Please enter password or \"q\" to exit program.");
           userInput = scnr.nextLine();
           
           //checks password with current user name password to see if it is correct
           confirmationString = currentUser.checkPass(userInput);
           
           /*reduces password attempts if password was incorrect and sends a 
           confirmation to main if password is correct
           */
           if ((!confirmationString.equals("q")) && ((!confirmationString.equals("null")))) {
               return confirmationString;
           }
           if (confirmationString.equals("null")) {
               System.out.println("Unkown command or wrong password, you have " + (2 - passwordAttempts) + " attempt(s) left.");
               
               passwordAttempts ++;
               
           }
           
        }
        return confirmationString;
        
        
    }
    
    //displays correct user data based on user type
    public static String displayUserData(User currentUser) throws Exception{
        Scanner scnr = new Scanner(System.in);
        
        //displays data from file based on currentUser type
        currentUser.getData();
        
        //prompts user for exit command or for new user log-in
        System.out.println("press any button to log in new user or press \"q\" exit program");
        return scnr.next();
    }
    
    //erases all currentUser data for new log-in
    public static void clearData(User currentUser) {
        currentUser.eraseData();
    }
   
    public static void main(String[] args) throws Exception{
        User currentUser = new User();
        String userInput = "";
        
        //loop allows user to exit at any time or forcefully exit
        while (!userInput.equals("q"))  {
            
            //clears any existing currentUser data
            clearData(currentUser);
            
            //gets and checks user name
            userInput = getUserName(currentUser);
            if (userInput.equals("q")){
                break;
            }
            
            //gets and checks user name
            userInput = getUserPassword(currentUser);
            if (userInput.equals("q")){
                break;
            }
            
            //displays currentUser data if password and user name are correct
            userInput = displayUserData(currentUser);
            if (userInput.equals("q")){
                break;
            }
                
            
        }
        //tells user that the program is exiting with a small animation
        System.out.print("Exiting program");
        for (int i=0; i < 3; i++){
            System.out.print(".");
            TimeUnit.SECONDS.sleep(1);
        }
        
    }
    
}

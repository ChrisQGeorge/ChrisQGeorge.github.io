
package ZooAuthenticationSystem.system;

import java.security.MessageDigest;

public class MD5Digest {
    
        //hashes username with an MD5 type hash and gives the hash back to the User class
	public String passwordHash(String userInput) throws Exception {
		String original = userInput;
		MessageDigest md = MessageDigest.getInstance("MD5");
		md.update(original.getBytes());
		byte[] digest = md.digest();
                StringBuffer sb = new StringBuffer();
		for (byte b : digest) {
			sb.append(String.format("%02x", b & 0xff));
		}
		return sb.toString(); //sb.toString() is what you'll need to compare password strings
	}

}


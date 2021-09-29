#include "SHA256.h"
#include "cryptoPP/sha.h"
#include "cryptoPP/cryptlib.h"
#include "cryptopp/hex.h"
#include "cryptopp/secblock.h"
#include "cryptopp/aes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/rijndael.h"

//digests password and salt with SHA256 hashing algorithm and returs hash string in hexidecimal
std::string SHA256::digestPass(std::string password, std::string salt) {
    std::string result;
    std::string saltedPass;

    //sha256 instance
    CryptoPP::SHA256 hash;

    //hexidecimal encoder instance
    CryptoPP::HexEncoder encoder;

    //applies given salt to given password
    saltedPass = password + salt;

    //clears password string
    CryptoPP::memset_z(&password[0], 0, password.size());

    //generates variable with byte datatype to store finished hash
    CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];

    //digests hash of salted password and assigns the result to digest
    hash.CalculateDigest(digest, (CryptoPP::byte*)saltedPass.c_str(), saltedPass.length());

    //clears saltedPass string
    CryptoPP::memset_z(&saltedPass[0], 0, saltedPass.size());

    //attaches hexidecimal encoder to result output string
    encoder.Attach(new CryptoPP::StringSink(result));

    //converts digest to hexidecimal and assigns it to result
    encoder.Put(digest, sizeof(digest));

    //ends encoding
    encoder.MessageEnd();

    //returns password hash as string
    return result;
};

//generates random salt with inharent randomness in the hosted computer
std::string SHA256::generateSalt() {
    //hexidecimal encoder instance
    CryptoPP::HexEncoder encoder;

    //Creates new salt variable with a default length of type secByteBlock 
    //This datatype is used becuase it works well with the OS_GenerateRandomBlock() function
    CryptoPP::SecByteBlock salt(CryptoPP::AES::DEFAULT_KEYLENGTH);

    std::string result;

    //Takes entropy from the system and generates a random salt value
    CryptoPP::OS_GenerateRandomBlock(true, salt, salt.size());

    //attaches hexidecimal encoder to result output string
    encoder.Attach(new CryptoPP::StringSink(result));

    //converts salt to hexidecimal and assigns it to result
    encoder.Put(salt, salt.size());

    //ends encoding
    encoder.MessageEnd();

    //returns salt as string
    return result;

}

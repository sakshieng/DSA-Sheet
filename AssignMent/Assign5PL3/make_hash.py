# Authentication for Server-Side Applications
# Server-side applications must pass two parameters in addition to the apikey parameter:

# ts - a timestamp (or other long string which can change on a request-by-request basis)
# hash - a md5 digest of the ts parameter, your private key and your public key(e.g. md5(ts+privateKey+publicKey)
# For example, a user with a public key of "1234" and a private key of "abcd" could construct a valid call as follows: http: // gateway.marvel.com/v1/public/comics?ts=1 & apikey=1234 & hash=ffd275c5130566a2916217b101f26150(the hash value is the md5 digest of 1abcd1234)

import hashlib

def make_hash(data):
  """Generates a hash value for the given data.

  Args:
    data: The data to hash.

  Returns:
    The hash value for the given data.
  """

  hasher = hashlib.md5()
  hasher.update(data.encode())
  return hasher.hexdigest()

# Example usage:


data = "This is the data to hash." + "c927e9d38d939964d373d3fcea47e2a3aa311711" + "cca03b385f58ec399040ddad9160740a"
hash_value = make_hash(data)

print(hash_value)

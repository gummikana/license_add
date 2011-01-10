import glob
import os
import sys


#Directory to files from
inputDirectory = './input/'



def findFiles( aDir, aDirName, files ):
    names = glob.glob(aDir + "/*.*") 

    #create a list of files
    if names:
        files.extend(names);
    
    # loop through every directory
    for f in os.listdir( aDir + "/" ):
        if ( os.path.isdir(aDir + f + "/") ):
            findFiles( aDir + f + "/", aDirName + f, files )


if __name__ == "__main__":

    files = [];
    findFiles(inputDirectory, "", files)
    
    with open("license.txt", "r+") as f:
        license_header = f.read() # read everything in the file

    print license_header

    for element in files:
	with open(element, "r+") as f:
	   old = f.read() # read everything in the file
           f.seek(0) # rewind
           f.write(license_header + "\n" + old) # write the new line before

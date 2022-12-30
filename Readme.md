# DISCLAIMER:
This Program is for Educational Purposes only.
You are responsible for any trouble you may cause by using this tool.

## REX
Rex is a Program designed to Install, hide and execute a command-prompt-payload for windows.

### Tutorial
To generate the infector, Download this repository, open a command prompt window. 
Within this window, navigate to the directory you downloaded this program to, and run 
```
Infectfactory.exe
```
The Program will prompt you to enter the payload you want to Infect anothe computer with. Please nonte that this payload can only have up to 1023 characters in total, as this is currently the programs limit for character paddding. 
After yoo've done that, the program will generate a 16-bit key and encrypt the payload with it using AES. Then, it will Generate a .exe, wich contains the Following:

- The Loader: Program to Load the encrypted registry key from the registry, decrypt it using the included key, an then execute it
- A Self-Destructor: Erases The Loader and all created Registry Keys, following by itself, to leave (except possibly event-logging trough tools loke Proc-Mon) no traces behind. Works only when ran with elevated permissions.

To Infect another Machine, you need to copy **all** files from the *"out"* - folder in the install directory to e.g. a Flash drive, move it to the victim's machine, and run the executable within it.
**THIS ONLY WORKS IF YOU ALREADY HAVE DONE PRIVILEGE ESCALATION AND HAVE AQUIRED AT LEAST ADMINISTRATIVE PRIVILEGES**
Now the following things are going to happen:

- The Directories 
   `C:\\Windows\\Media\\Maths`
   and
   `C:\\Windows\\Web\\Wallpaper\\Maths`
   will be created, with the first one being where the loader is stored, and the latter being where the self-destructor is stored.
- The file `calc.exe` is copied to each of the folders. `calc.exe` is a legitimate copy from microsoft and does not contain any malware.
- Two different `.dll`'s with the name `WindowsCodecs.dll` are created in their respective folders, with one being the loader and the other being the self-destructor.
- The Value `license`, wich contains the encrypted payload, is created under the Registry key `HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\BitLocker`. This **should (?)** not interfere with the standard procedures of a windows installation.
- A scheduled task `Do Math` is created, wich runs the `calc.exe` contained in the folder of the Loader on every startup.


### How it works
 The Principle is actually fairly simple: The payload is aes encrypted (for obfuscation) and hidden in the registry. The loader is started from calc.exe (through dll-sideloading) to at least partially bamboozle the Anti-Virus into thinking the stuff the loader is doing is legit. *(Please note that windows defender doesnt care what  program is doing smth, it only cares if the behaviour matches that of an attacker. Source: Experienced it myself with Regedit.exe . The one my windows was shipped with. Through GUI. On my own Computer..)* 
 The way the infector is crafted is by injecting the data into buffers within the compiled programs, and then injecting the compiled programs into the Infector preset.
 For mor details, take a look at the source code.

### Tests:
#### Tested and working OS':
- None *(SKULL-EMOJI)*
#### OS' That have to be tested yet:
- WINDOWS 11 Pro
- WINDOWS 11 HOME
- WINDOWS 10 Pro
- WINDOWS 10 Home
- WINDOWS 8 Pro
- Windows 8 Home
- Windows 7

# DISCLAIMER:
## AS I SAID, This Program is for Educational Purposes only. You are responsible for any trouble you may cause by using this tool.

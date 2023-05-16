## Setup and installation

### 1. Setup VSCode & PlatformIO
1. download VSCode from the [link provided](https://code.visualstudio.com/).
2. once downloaded, run or open via cli using the `code` function.

3. Ensure you have access to a C Compiler, if not then follow [this tutorial](https://code.visualstudio.com/docs/languages/cpp) on the topic

4. once open, select the extensions tab, search and install the PlatformIO extension.

![](/Media/PlatformIO.png)


5. Once downloaded open the [Algae Panel folder](/Software/Algae%20Project/) inside the Software folder inside the Algae Panel repo. this can be done via ```ctrl+K -> ctrl+O ```

6. Once done you should see the platformIO symbol in the primary bar ![](/Media/PlatformIO_Symbol.png) as well as a lot of new buttons down in the status bar.

 ![](/Media/Status_Bar.png)

These buttons starting from the tick do the following

| Symbol      | Image | Description  |
| ----------- | ----------- |  ---- |
| Tick      | ![](/Media/tick.png)      | builds the currently selected environment  |
| Arrow  | ![](/Media/arrow.png)        | builds then uploads the selected environment to an attached board  |
| Trashcan  | ![](/Media/trash.png)        | cleans the currently attached arduino, replacing any code with a blink script  |
| Beaker  | ![](/Media/beaker.png)        | runs all defined unit tests  |
| Plug  | ![](/Media/plug.png)        | Creates serial terminal connected to arduino  |
| terminal  | ![](/Media/terminal.png)       | Creates a blank terminal (not very useful) |
| folder  | ![](/Media/env.png)        | allows you to select the environment to build  |

---

## To run code
- create a new environment (inside the [platformio.ini file](/Software/Algae%20Project/platformio.ini)) or select a prexisting environment
- connect arduino to computer
- Upload the selected environment to the arduino via the Arrow Icon ![](/Media/arrow.png)


### Tips & Tricks

- if you're struggling to upload the file
    - ensure that no other terminal has access to the COM port (Open Serial Terminals are an often point of error)

    - if the arduino is constantly sending a stream of serial data back, you can press the power button to reset, then quickly upload before the arduino starts sending serial data

    - restart your computer

    - try another arduino


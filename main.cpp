/* 
 * PJLink Projector Emulator
 * 
 * File:   main.cpp
 * Author: Alex McLain <alex@alexmclain.com>
 * 
 * Website:
 * [TBD]
 * 
 * PJLink Specification:
 * http://pjlink.jbmia.or.jp/english/data/PJLink%20Specifications100.pdf
 * 
 * 
 * ========================================================================
 * Copyright 2012 Alex McLain
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "UI.h"
#include <unistd.h>
#include <iostream>

int main(int argc, char** argv) {
    int c;
    while ((c = getopt(argc, argv, "h")) != -1) {
        switch (c) {
        case 'h':
            std::cout <<
                "HOTKEYS:\n"
                "1    Power State\n"
                "2    Input\n"
                "3    A/V Mute\n"
                "4    Error Code\n"
                "5    Lamp Status\n"
                "6    Lamp Hours\n\n"
                "h    Console Page Down\n"
                "j    Console Line Down\n"
                "k    Console Line Up\n"
                "l    Console Page Up\n\n"
                "g    Console Home\n"
                "G    Console End\n\n"
                "o    Listen\n\n"
                "q    Quit Application\n\n"
                ":    Command Prompt\n\n"
                "COMMANDS:\n"
                "port [number]\n"
                "    Set the TCP/IP port number to listen on.\n\n"
                "q | quit | exit\n"
                "    Quit the application." << std::endl;
            return 0;
        default:
            return -1;
        }
    }

    UI *ui = UI::getInstance();
    ui->initialize();
    ui->shutdown();
    return 0;
}

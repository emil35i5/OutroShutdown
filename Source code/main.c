#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")

void playMP3(const char* filepath) {
    char command[256];
    sprintf(command, "open \"%s\" type mpegvideo alias mymp3", filepath);
    mciSendString(command, NULL, 0, NULL);
    mciSendString("play mymp3", NULL, 0, NULL);
}

void pauseMP3() {
    mciSendString("pause mymp3", NULL, 0, NULL);
}

void resumeMP3() {
    mciSendString("resume mymp3", NULL, 0, NULL);
}

void fadeOutMP3(int duration_ms) {
    int volume = 1000;                  // start at full volume
    int steps = 20;                     // how many volume steps
    int delay = duration_ms / steps;   // delay between steps

    for (int i = 0; i < steps; i++) {
        volume -= 1000 / steps;
        if (volume < 0) volume = 0;

        char cmd[64];
        sprintf(cmd, "setaudio mymp3 volume to %d", volume);
        mciSendString(cmd, NULL, 0, NULL);
        Sleep(delay);
    }

    mciSendString("stop mymp3", NULL, 0, NULL);
    mciSendString("close mymp3", NULL, 0, NULL);
}


void turnOffScreen() {
    SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
}

void shutdownPC() {
    system("shutdown -s -t 0");
}

int main() {
    printf("\n");
    printf("  / __ \\      | |           / ____| |         | |    | |\n"
       " | |  | |_   _| |_ _ __ ___| (___ | |__  _   _| |_ __| | _____      ___ __\n"
       " | |  | | | | | __| '__/ _ \\\\___ \\| '_ \\| | | | __/ _` |/ _ \\ \\ /\\ / / '_ \\\n"
       " | |__| | |_| | |_| | | (_) |___) | | | | |_| | || (_| | (_) \\ V  V /| | | |\n"
       "  \\____/ \\__,_|\\__|_|  \\___/_____/|_| |_|\\__,_|\\__\\__,_|\\___/ \\_/\\_/ |_| |_|\n"
       "\n");
    printf("Turn off your computer with music\n");
    printf("\n");
    printf("Thanks to karl6986 on GitHub for the original project: Awesome-shutdown\n");
    printf("Music by TheFatRat - Xenogenesis (Outro Song)\n");
    printf("emil.ystrom.dk\n");
    playMP3("song.mp3");  // <-- Update path if needed

    Sleep(57900);  // 57.9 sec
    //pauseMP3();
    BlockInput(TRUE);
    turnOffScreen();

    //resumeMP3();
    fadeOutMP3(7700);  // Simulate fade

    Sleep(10000);
    BlockInput(FALSE);
    shutdownPC();

    return 0;
}

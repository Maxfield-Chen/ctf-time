/* compiled with: gcc pwn400.c -o pwn400 */
/*
credit for the images go to:
http://textart4u.blogspot.com/2013/06/nyan-cat-text-art.html
http://textart4u.blogspot.com/2013/10/doge-meme-face-text-art-for-facebook.html
http://www.ascii-code.com/ascii-art/animals/insects/snails.php
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_ANIMALS 10

unsigned int get_choice(void)
{
    unsigned int res = 0, c;
    fflush(stdout);
    scanf("%u", &res);
    while((c = getchar()))
        if(c == '\n' || c == EOF)
            break;
    return res;
}

struct cat_t {
    void(*print)(void);
    void(*pet)(void);
};

struct dog_t {
    unsigned int age;
    void(*print)(void);
    void(*print_age)(int);
};

struct snail_t {
    void (*print)(void);
    void (*shell)(void);
};

void print_nyancat(void) {
    printf(
        "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
        "░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░\n"
        "░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░\n"
        "░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░\n"
        "░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░\n"
        "░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░\n"
        "░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░\n"
        "░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░\n"
        "░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░\n"
        "░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░\n"
        "░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░\n"
        "░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░\n"
        "░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░\n"
        "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
    );
}

void cat_pet(void) {
    if(rand() % 4 < 2) {
        printf("purr...\n");
    } else {
        printf("*hiss*\n");
    }
}

void print_doge(void) {
    printf(
        "         ▄              ▄    \n"
        "        ▌▒█           ▄▀▒▌   \n"
        "        ▌▒▒▀▄       ▄▀▒▒▒▐   \n"
        "       ▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐   \n"
        "     ▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐   \n"
        "   ▄▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀██▀▒▌   \n"
        "  ▐▒▒▒▄▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▒▌  \n"
        "  ▌▒▒▐▄█▀▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐  \n"
        " ▐▒▒▒▒▒▒▒▒▒▒▒▌██▀▒▒▒▒▒▒▒▒▀▄▌ \n"
        " ▌▒▀▄██▄▒▒▒▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌ \n"
        " ▌▀▐▄█▄█▌▄▒▀▒▒▒▒▒▒░░░░░░▒▒▒▐ \n"
        "▐▒▀▐▀▐▀▒▒▄▄▒▄▒▒▒▒▒░░░░░░▒▒▒▒▌\n"
        "▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒░░░░░░▒▒▒▐ \n"
        " ▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒▒▒░░░░▒▒▒▒▌ \n"
        " ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐  \n"
        "  ▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▌  \n"
        "    ▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀   \n"
        "   ▐▀▒▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀     \n"
        "  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▀        \n"
    );
}

void print_dog_years(int years) {
    printf("%d in human years is %d in dog years.\n", years, 7*years);
}

void print_snail(void) {
    printf(
        "         __,._       \n"
        "        /  _  \\      \n"
        "       |  6 \\  \\  oo \n"
        "        \\___/ .|__|| \n"
        " __,..=\"^  . , \"  , \\\n"
        "<.__________________/\\\n"
    );
}

void snail_shell() {
    setenv("PS1",
"           eed*^^^^^^^^^**be,\n"
"        .d^                  ^b.\n"
"      .d                        b.\n"
"    .^         ..eeeeee..         ^.\n"
"   P        z$*^        ^*e.        9.\n"
"  A       d^                ^b       A\n"
" J       J    .e*^^^^^^%c     A       L\n"
"A       A    d^          $     L      A\n"
"#       %   d      d**y  ^L    %      #\n"
"#       %   $     $ ,, Y  .$   %      #       _ _ \n"
"#       %   $     *  ^^^   F   %      #      (@)@)\n"
"#       V    4.    $.   .e^    Y      #        % %\n"
"#        $    *.    ^^^^     .Y      V         $ $\n"
"#        ^b     ^b.      ..e*       Y         .eeee\n"
"V         ^$      ^^eeee^^        eP         A     %\n"
" Y         eb                ..d*^         _#    O %\n"
" I    _e%*^^^^*$ee......ee$*^eeeeeeeezee$**^       $\n"
"  V ,^                                            B\n"
"  J^                                        _,e=^^\n"
".^##########################################^^\n"
    , 1);
    system("sh");
}

unsigned int print_main_menu() {
    printf("-- Fairgame Pwn400 Zoo Menu --\n"
           "1. Add an animal\n"
           "2. Remove an animal\n"
           "3. Interact with an animal\n"
           "4. Quit\n"
           "------------------------------\n"
           "Enter Choice: ");
    return get_choice();
}

unsigned int print_add_menu() {
    printf("-- What kind of animial do you want to add? --\n"
           "1. Add a cat\n"
           "2. Add a dog\n"
           "3. Add a snail\n"
           "4. Cancel\n"
           "----------------------------------------------\n"
           "Enter Choice: ");
    return get_choice();
}

unsigned int print_remove_menu() {
    printf("-- What kind of animial do you want to remove? --\n"
           "1. Remove a cat\n"
           "2. Remove a dog\n"
           "3. Remove a snail\n"
           "4. Cancel\n"
           "-------------------------------------------------\n"
           "Enter Choice: ");
    return get_choice();
}

unsigned int print_interact_menu() {
    printf("-- What kind of animial do you want to interact with? --\n"
           "1. Interact with a cat\n"
           "2. Interact with a dog\n"
           "3. Interact with a snail\n"
           "4. Cancel\n"
           "--------------------------------------------------------\n"
           "Enter Choice: ");
    return get_choice();
}

void do_add(struct cat_t **cats, struct dog_t **dogs, struct snail_t **snails) {
    unsigned int choice;
    unsigned int age;
    size_t i;
    choice = print_add_menu();
    switch(choice) {
        default: return;
        case 1: {
            for(i=0; (i < MAX_ANIMALS) && (cats[i] != 0); i++);
            if(i < MAX_ANIMALS) {
                cats[i] = (struct cat_t*)malloc(sizeof(struct cat_t));
                cats[i]->print = &print_nyancat;
                cats[i]->pet = &cat_pet;
            }
        } break;
        case 2: {
            for(i=0; (i < MAX_ANIMALS) && (dogs[i] != 0); i++);
            if(i < MAX_ANIMALS) {
                dogs[i] = (struct dog_t*)malloc(sizeof(struct dog_t));
                printf("How old is the dog?\nAge: ");
                dogs[i]->age = get_choice();
                dogs[i]->print = &print_doge;
                dogs[i]->print_age = &print_dog_years;
            }
        } break;
        case 3: {
            for(i=0; (i < MAX_ANIMALS) && (snails[i] != 0); i++);
            if(i < MAX_ANIMALS) {
                snails[i] = (struct snail_t*)malloc(sizeof(struct snail_t));
                snails[i]->print = &print_snail;
                snails[i]->shell = (void(*)(void))(void*)"It's not going to be that easy.";
            }
        } break;
    }
}

void do_remove(struct cat_t **cats, struct dog_t **dogs, struct snail_t **snails) {
    unsigned int choice;
    unsigned int index;
    choice = print_remove_menu();
    switch(choice) {
        default: return;
        case 1: {
            printf("Which cat?\nIndex: ");
            index = get_choice();
            if((0 <= index) && (index < MAX_ANIMALS)) {
                free(cats[index]);
            }
        } break;
        case 2: {
            printf("Which dog?\nIndex: ");
            index = get_choice();
            if((0 <= index) && (index < MAX_ANIMALS)) {
                free(dogs[index]);
            }
        } break;
        case 3: {
            printf("Which snail?\nIndex: ");
            index = get_choice();
            if((0 <= index) && (index < MAX_ANIMALS)) {
                free(snails[index]);
            }
        } break;
    }
}

void do_interaction(struct cat_t **cats, struct dog_t **dogs, struct snail_t **snails) {
    unsigned int choice;
    unsigned int index;
    choice = print_interact_menu();
    switch(choice) {
        default: return;
        case 1: {
            printf("Which cat?\nIndex: ");
            index = get_choice();
            printf("-- What do you want to do to the cat? --\n"
                   "1. Look at it\n"
                   "2. Pet it\n"
                   "3. Cancel\n"
                   "----------------------------------------\n"
                   "Enter Choice: ");
            choice = get_choice();
            switch(choice) {
                default: return;
                case 1: cats[index]->print(); return;
                case 2: cats[index]->pet(); return;
            }
        }
        case 2: {
            printf("Which dog?\nIndex: ");
            index = get_choice();
            printf("-- What do you want to do to the dog? --\n"
                   "1. Look at it\n"
                   "2. Learn its age\n"
                   "3. Cancel\n"
                   "----------------------------------------\n"
                   "Enter Choice: ");
            choice = get_choice();
            switch(choice) {
                default: return;
                case 1: dogs[index]->print(); return;
                case 2: dogs[index]->print_age(dogs[index]->age); return;
            }
        }
        case 3: {
            printf("Which snail?\nIndex: ");
            index = get_choice();
            printf("-- What do you want to do to the snail? --\n"
                   "1. Look at it\n"
                   "2. Take its shell\n"
                   "3. Cancel\n"
                   "------------------------------------------\n"
                   "Enter Choice: ");
            choice = get_choice();
            switch(choice) {
                default: return;
                case 1: snails[index]->print(); return;
                case 2: snails[index]->shell(); return;
            }
        }
    }
}

int main() {
    struct cat_t *cats[MAX_ANIMALS] = {0};
    struct dog_t *dogs[MAX_ANIMALS] = {0};
    struct snail_t *snails[MAX_ANIMALS] = {0};

    unsigned int choice = 0;

    while(1)
    {
        choice = print_main_menu();

        switch(choice) {
            default: return 0;
            case 1: do_add(&cats[0], &dogs[0], &snails[0]); break;
            case 2: do_remove(&cats[0], &dogs[0], &snails[0]); break;
            case 3: do_interaction(&cats[0], &dogs[0], &snails[0]); break;
        }
    }

    return 0;
}


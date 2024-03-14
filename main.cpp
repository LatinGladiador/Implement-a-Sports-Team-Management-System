#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Enum for the position of the player
typedef enum {Goalkeeper, Defender, Midfielder, Forward, Unknown} position_player;

//Structure for the player
typedef struct {
    int id;
    char name[300];
    position_player pos;
    int age;
    int goals;
} soccer_team_player;

soccer_team_player team[100000];
int teamSize = 0;

//Function to validate soccer team player data
int valid_for_soccer_team_player(const soccer_team_player *new_soccer_team_player) {
    //Chekc age and goals
    if ( new_soccer_team_player->age < 18 || new_soccer_team_player->age > 100 || new_soccer_team_player->goals < 0 ||new_soccer_team_player->goals >= 1000) {
        return 0;
    }
    //Check name  format and length
    if (!(new_soccer_team_player->name[0] >= 'A' && new_soccer_team_player->name[0] <= 'Z') || strlen(new_soccer_team_player->name) < 2 || strlen(new_soccer_team_player->name) > 15) {
        return 0;
    }
    //Check that the name contains only letters and numbers
    for (int i = 0; i < strlen(new_soccer_team_player->name); i++) {
        char * name = new_soccer_team_player->name;
        if((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')){

        } else {
            return 0;
        }
    }
    return 1;
}
//Function to add a soccer team player
void addsoccer_team_player(int id, char name[], position_player pos, int age, int goals, FILE *outputFile) {
    //Check if the player is valid
    for (int i = 0; i < teamSize; i++) {
        if (team[i].id == id) {
            fprintf(outputFile, "Invalid inputs\n");
            fclose(outputFile);
            exit(0);
        }
    }
    //Create a new soccer team player
    soccer_team_player new_soccer_team_player;
    new_soccer_team_player.id = id;
    strcpy(new_soccer_team_player.name, name);
    new_soccer_team_player.pos = pos;
    new_soccer_team_player.age = age;
    new_soccer_team_player.goals = goals;
    //Check if the player's position is valid and if the data is valid
    if (new_soccer_team_player.pos < Goalkeeper || new_soccer_team_player.pos > Forward || !valid_for_soccer_team_player(&new_soccer_team_player)) {
        fprintf(outputFile, "Invalid inputs\n");
        fclose(outputFile);
        exit(0);
    }
    //Addn the new player to the team
    team[teamSize] = new_soccer_team_player;
    teamSize++;
}
//Function to delete a soccer team player by ID
void deletesoccer_team_player(int id, FILE *outputFile) {
    int found = 0;
    //Find the player in the team and delete it
    for (int i = 0; i < teamSize; i++) {
        if (team[i].id == id) {
            found = 1;
            for (int j = i; j < teamSize - 1; j++) {
                team[j] = team[j + 1];
            }
            teamSize--;
            break;
        }
    }
    //If the player was not found, print an error message
    if (!found) {
        fprintf(outputFile, "Impossible to delete\n");
    }
}
//Function to display all soccer team players
void displayteam_soccer_player(FILE *outputFile) {
    //Check if the team is empty
    if (teamSize == 0) {
        fprintf(outputFile, "Invalid inputs\n");
        fclose(outputFile);
        exit(0);
    }
    //Display information about the team
    for (int i = 0; i < teamSize; i++) {
        const char *posStr;
        switch (team[i].pos) {
            case Goalkeeper:
                posStr = "Goalkeeper";
                break;
            case Defender:
                posStr = "Defender";
                break;
            case Midfielder:
                posStr = "Midfielder";
                break;
            case Forward:
                posStr = "Forward";
                break;
            default:
                posStr = "Unknown";
        }
        fprintf(outputFile, "ID: %d, Name: %s, Position: %s, Age: %d, Goals: %d\n",
                team[i].id, team[i].name, posStr, team[i].age, team[i].goals);
    }
}
//Function to search a soccer team player by ID
int searchsoccer_team_player(int id, FILE *outputFile) {
    int found = 0;
    //Search the player by ID
    for (int i = 0; i < teamSize; i++) {
        if (team[i].id == id) {
            found = 1;
            break;
        }
    }
    //Display wether the player was found or not
    if (found) {
        fprintf(outputFile, "Found\n");
    } else {
        fprintf(outputFile, "Not found\n");
    }

    return found;
}
//Function to update the information of a soccer team player
void updatesoccer_team_player(int id, char name[], position_player pos, int age, int goals, FILE *outputFile) {
    int found = 0;
    //Find the player and update their information
    for (int i = 0; i < teamSize; i++) {
        if (team[i].id == id) {
            found = 1;
            strcpy(team[i].name, name);
            team[i].pos = pos;
            team[i].age = age;
            team[i].goals = goals;
            //Check if the update is valid
            if (team[i].pos < Goalkeeper || team[i].pos > Forward || !valid_for_soccer_team_player(&team[i])) {
                fprintf(outputFile, "Invalid inputs\n");
                fclose(outputFile);
                exit(0);
            }
            break;
        }
    }
    //If the player was not found, print an error message
    if (!found) {
        fprintf(outputFile, "Invalid inputs\n");
        fclose(outputFile);
        exit(0);
    }
}
//Function to convert a string to a position_player enum
position_player stringposition_player(const char *posStr) {
    if (strcmp(posStr, "Goalkeeper") == 0) {
        return Goalkeeper;
    } else if (strcmp(posStr, "Defender") == 0) {
        return Defender;
    } else if (strcmp(posStr, "Midfielder") == 0) {
        return Midfielder;
    } else if (strcmp(posStr, "Forward") == 0) {
        return Forward;
    } else {
        return Unknown;
    }
}
//Function to check if a string contains only digits
bool checck_string_integer(char *sstring) {
    for (int i = 0; i < strlen(sstring); i++) {
        if (!(sstring[i] >= '0' && sstring[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

int main() {
    //Open input and output files
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    char action[100];
    int id, age, goals;
    char name[300];
    char posStr[160];
    position_player pos;
    int i = 0;
    //Read and process the input
    while (fscanf(inputFile, "%s", action) != EOF) {
        i++;
        if (strcmp(action, "Add") == 0) {
            char tempid[300];
            char tempage[300];
            char tempgoals[300];

            fscanf(inputFile, "%s%s%s%s%s", tempid, name, posStr, tempage, tempgoals);
            if (!checck_string_integer(tempid) || !checck_string_integer(tempage) || !checck_string_integer(tempgoals)) {
                fprintf(outputFile, "Invalid inputs\n");
                fclose(inputFile);
                fclose(outputFile);
                exit(0);
            }
            id = atoi(tempid);
            age = atoi(tempage);
            goals = atoi(tempgoals);

            if (strcmp(posStr, "Goalkeeper") == 0 || strcmp(posStr, "Defender") == 0 || strcmp(posStr, "Midfielder") == 0 || strcmp(posStr, "Forward") == 0) {
                pos = stringposition_player(posStr);
                addsoccer_team_player(id, name, pos, age, goals, outputFile);
            } else {
                fprintf(outputFile, "Invalid inputs\n");
                fclose(inputFile);
                fclose(outputFile);
                exit(0);
            }

        } else if (strcmp(action, "Delete") == 0) {
            char tempid[300];
            fscanf(inputFile, "%s", tempid);
            if(!checck_string_integer(tempid)) {
                fprintf(outputFile, "Invalid inputs\n");
                fclose(inputFile);
                fclose(outputFile);
                exit(0);
            }
            id = atoi(tempid);
            deletesoccer_team_player(id, outputFile);
        } else if (strcmp(action, "Display") == 0) {
            displayteam_soccer_player(outputFile);
        } else if (strcmp(action, "Search") == 0) {
            char tempid[300];
            fscanf(inputFile, "%s", tempid);
            if(!checck_string_integer(tempid)) {
                fprintf(outputFile, "Invalid inputs\n");
                fclose(inputFile);
                fclose(outputFile);
                exit(0);
            }
            id = atoi(tempid);
            searchsoccer_team_player(id, outputFile);
        } else if (strcmp(action, "Update") == 0) {
            char tempid[300];
            char tempage[300];
            char tempgoals[300];

            fscanf(inputFile, "%s%s%s%s%s", tempid, name, posStr, tempage, tempgoals);
            if (!checck_string_integer(tempid) ||!checck_string_integer(tempage) ||!checck_string_integer(tempgoals)) {
                fprintf(outputFile, "Invalid inputs\n");
                fclose(inputFile);
                fclose(outputFile);
                exit(0);
            }
            id = atoi(tempid);
            age = atoi(tempage);
            goals = atoi(tempgoals);
            if (strcmp(posStr, "Goalkeeper") == 0 || strcmp(posStr, "Defender") == 0 || strcmp(posStr, "Midfielder") == 0 || strcmp(posStr, "Forward") == 0) {
                pos = stringposition_player(posStr);
            } else {
                fprintf(outputFile, "Invalid inputs\n");
                fclose(inputFile);
                fclose(outputFile);
                exit(0);
            }
            updatesoccer_team_player(id, name, pos, age, goals, outputFile);
        }else {
            fprintf(outputFile, "Invalid inputs\n");
            fclose(inputFile);
            fclose(outputFile);
            exit(0);
        }
    }
    //Closes input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
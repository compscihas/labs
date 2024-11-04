#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * param   fileName    File name of dungeon level.
 * param   maxRow      Number of rows in the dungeon table (aka height).
 * param   maxCol      Number of columns in the dungeon table (aka width).
 * param   player      Player object by reference to set starting position.
 * return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream levelFs(fileName);
    int count = 0;
    if (!levelFs.is_open()){
        return nullptr;
    }
    levelFs >> maxRow >> maxCol;
    if (levelFs.fail() == 1)
    {
        return nullptr;
    }
    if (levelFs.fail() == 1)
    {
        return nullptr;
    }
    if(maxCol <= 0){
        return nullptr;
    }
    if((maxRow > INT32_MAX / maxCol) || (maxCol > INT32_MAX / maxRow)){
        return nullptr;
    }
    levelFs >> player.row;
    if(levelFs.fail() == 1){
        return nullptr;
    }
    if(player.row >= maxRow || player.row < 0){
        return nullptr;
    }
    if (levelFs >> player.col){
        if (levelFs.fail() == 1){
            return nullptr;
        }
        ++count;
    }
    if(count == 0){
        return nullptr;
    }
    if((player.col>= maxCol) || (player.col < 0)){
        return nullptr;
    }
    char** realLevel = createMap(maxRow, maxCol);
    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < maxCol; ++j) {
            char ch;
            levelFs >> ch;
            if (levelFs.fail()) {
                deleteMap(realLevel, maxRow);
                return nullptr;
            }
            if (ch == '\n') {
                --j;
                continue;
            }

            realLevel[i][j] = ch;
        }
    }
    if (realLevel[player.row][player.col] != TILE_OPEN) {
        deleteMap(realLevel, maxRow);
        return nullptr;
    }


    realLevel[player.row][player.col] = TILE_PLAYER;

    return realLevel;
}
/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * param   input       Character input by the user which translates to a direction.
 * param   nextRow     Player's next row on the dungeon map (up/down).
 * param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if(input == MOVE_UP){
        nextRow -= 1;
    }
    else if(input == MOVE_DOWN){
        nextRow += 1;
    }
    else if(input == MOVE_LEFT){
        nextCol -= 1;
    }
    else if(input == MOVE_RIGHT){
        nextCol += 1;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * param   maxRow      Number of rows in the dungeon table (aka height).
 * param   maxCol      Number of columns in the dungeon table (aka width).
 * return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    char** map = new char*[maxRow];
    for (int i = 0; i < maxRow; ++i) {
        map[i] = new char[maxCol];
    }


    for (int i = 0; i < maxRow; ++i) {
        for (int j = 0; j < maxCol; ++j) {
            map[i][j] = TILE_OPEN;
        }
    }

    return map;
}
/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * param   map         Dungeon map.
 * param   maxRow      Number of rows in the dungeon table (aka height).
 * return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if(map == nullptr){
        maxRow = 0;
        return;
    }
    for (int i = 0; i < maxRow; i++) {
        delete[] map[i];
    }
    delete[] map;
    map = nullptr;
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * param   map         Dungeon map.
 * param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    if (map == nullptr || maxRow <= 0 || maxCol <= 0)
        return nullptr;

    int row = 0;
    int col = 0;

    char **newmap = new char *[maxRow * 2] {};
    for (int i = 0; i < maxRow * 2; ++i)
    {
        newmap[i] = new char[maxCol * 2];
    }

    for (int i = 0; i < maxRow; ++i)
    {
        for (int j = 0; j < maxCol; ++j)
        {
            if (map[i][j] == TILE_PLAYER)
            {
                row = i;
                col = j;
            }
            newmap[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < maxRow; ++i)
    {
        for (int j = maxCol; j < maxCol * 2; ++j)
        {
            newmap[i][j] = map[i][j - maxCol];
        }
    }

    // bottom left corner
    for (int i = maxRow; i < maxRow * 2; ++i)
    {
        for (int j = 0; j < maxCol; ++j)
        {
            newmap[i][j] = map[i - maxRow][j];
        }
    }

    // bottom right
    for (int i = maxRow; i < maxRow * 2; ++i)
    {
        for (int j = maxCol; j < maxCol * 2; ++j)
        {
            newmap[i][j] = map[i - maxRow][j - maxCol];
        }
    }

    newmap[row + maxRow][col] = TILE_OPEN;
    newmap[row][col + maxCol] = TILE_OPEN;
    newmap[row + maxRow][col + maxCol] = TILE_OPEN;

    for (int i = 0; i < maxRow; ++i)
    {
        delete[] map[i];
    }

    delete[] map;

    map = newmap;

    maxRow *= 2;
    maxCol *= 2;

    return map;
}


/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * param   map         Dungeon map.
 * param   maxRow      Number of rows in the dungeon table (aka height).
 * param   maxCol      Number of columns in the dungeon table (aka width).
 * param   player      Player object to by reference to see current location.
 * param   nextRow     Player's next row on the dungeon map (up/down).
 * param   nextCol     Player's next column on dungeon map (left/right).
 * return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    int status;
    if (nextRow == maxRow){
        nextRow -= 1;
        status = STATUS_STAY;
    }
    else if(nextCol == maxCol){
        nextCol -= 1;
        status = STATUS_STAY;
    }
    else if (nextRow == -1){
        nextRow += 1;
        status = STATUS_STAY;
    }
    else if (nextCol == -1){
        nextCol += 1;
        status = STATUS_STAY;
    }
    else if((map[nextRow][nextCol] == TILE_MONSTER) || (map[nextRow][nextCol] == TILE_PILLAR)){
        nextRow = player.row;
        nextCol = player.col;
        status = STATUS_STAY;
    }
    else{
        if(map[nextRow][nextCol] == TILE_TREASURE){
            player.treasure += 1;
            map[player.row][player.col] = TILE_OPEN;
            player.row = nextRow;
            player.col = nextCol;
            map[player.row][player.col] = TILE_PLAYER;
            status = STATUS_TREASURE;
        }
        else if(map[nextRow][nextCol] == TILE_AMULET){
            map[player.row][player.col] = TILE_OPEN;
            player.row = nextRow;
            player.col = nextCol;
            map[player.row][player.col] = TILE_PLAYER;
            status = STATUS_AMULET;
        }
        else if(map[nextRow][nextCol] == TILE_DOOR){
            status = STATUS_LEAVE;
            map[player.row][player.col] = TILE_OPEN;
            player.row = nextRow;
            player.col = nextCol;
            map[player.row][player.col] = TILE_PLAYER;
        }
        else if(map[nextRow][nextCol] == TILE_EXIT){
            if(player.treasure > 0){
                status = STATUS_ESCAPE;
                map[player.row][player.col] = TILE_OPEN;
                player.row = nextRow;
                player.col = nextCol;
                map[player.row][player.col] = TILE_PLAYER;
            }
            else{
                nextRow = player.row;
                nextCol = player.col;
                status = STATUS_STAY;
            }
        }
        else{
            status = STATUS_MOVE;
            map[player.row][player.col] = TILE_OPEN;
            player.row = nextRow;
            player.col = nextCol;
            map[player.row][player.col] = TILE_PLAYER;
        }
    }
    return status;
}
/*int ogRow = maxRow;
            int ogCol = maxCol;
            map[player.row][player.col] = TILE_OPEN;
            player.row = nextRow;
            player.col = nextCol;
            map[player.row][player.col] = TILE_PLAYER;
            map = resizeMap(map, maxRow, maxCol);
            for(int i = 0; i < ogRow; i++){
                for(int j = 0; j < ogCol; j++){
                    map[i + ogRow][j] = map[i][j];
                    map[i][j + ogCol] = map[i][j];
                }
            }
        }*/
/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * param   map         Dungeon map.
 * param   maxRow      Number of rows in the dungeon table (aka height).
 * param   maxCol      Number of columns in the dungeon table (aka width).
 * param   player      Player object by reference for current location.
 * return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char **map, int maxRow, int maxCol, const Player &player)
{

    int monster = 0;
    // check if monster is up
    for (int i = player.row - 1; i >= 0; i--)
    {
        if (map[i][player.col] == TILE_PILLAR)
        {
            break;
        }
        if (map[i][player.col] == TILE_MONSTER)
        {
            if (player.row - i == 1)
            {
                map[i + 1][player.col] = TILE_MONSTER;
                map[i][player.col] = TILE_OPEN;

                ++monster;
            }
            else
            {
                map[i + 1][player.col] = TILE_MONSTER;
                map[i][player.col] = TILE_OPEN;
            }
        }
    }

    // below
    for (int i = player.row + 1; i < maxRow; ++i)
    {
        if (map[i][player.col] == TILE_PILLAR)
        {
            break;
        }
        if (map[i][player.col] == TILE_MONSTER)
        {
            if (i - player.row == 1)
            {
                map[i - 1][player.col] = TILE_MONSTER;
                map[i][player.col] = TILE_OPEN;
                ++monster;
            }
            else
            {
                map[i - 1][player.col] = TILE_MONSTER;
                map[i][player.col] = TILE_OPEN;
            }
        }
    }

    // left
    for (int i = player.col - 1; i >= 0; --i)
    {
        if (map[player.row][i] == TILE_PILLAR)
        {
            break;
        }
        if (map[player.row][i] == TILE_MONSTER)
        {
            if (player.col - i == 1)
            {
                map[player.row][i + 1] = TILE_MONSTER;
                map[player.row][i] = TILE_OPEN;
                ++monster;
            }
            else
            {
                map[player.row][i + 1] = TILE_MONSTER;
                map[player.row][i] = TILE_OPEN;
            }
        }
    }

    // right
    for (int i = player.col + 1; i < maxCol; ++i)
    {
        if (map[player.row][i] == TILE_PILLAR)
        {
            break;
        }
        if (map[player.row][i] == TILE_MONSTER)
        {
            if (i - player.col == 1)
            {
                map[player.row][i - 1] = TILE_MONSTER;
                map[player.row][i] = TILE_OPEN;
                ++monster;
            }
            else
            {
                map[player.row][i - 1] = TILE_MONSTER;
                map[player.row][i] = TILE_OPEN;
            }
        }
    }

    if (monster > 0)
        return true;
    return false;
}
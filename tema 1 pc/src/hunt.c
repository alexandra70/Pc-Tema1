#include "hunt.h"
#include <stdio.h>
#include<math.h>
/* Task 1 - Axii */

uint16_t find_spell(uint64_t memory)
{
    /*
     * The spell is 16 bits and they are in the memory exactly after 5
     * consecutive bits of 1:
     *
     *            high                                             low
     *                [][][x]...[x][x][x][1][1][1][1][1][]...[][][]
     *                    |----16bits---|
     *                          Spell
     *
     * There is only 1 group of 5 consecutive bits of 1 and the other groups
     * have less than consecutive bits of 1
     * Steps:
     * - find 5 consecutive bits of 1
     * - the NEXT 16 bits == spell
     */

    uint16_t res = -1;

    /* TODO */


    uint64_t mask;
    uint8_t i;
    int bit[64] = { 0 };
    //printf("%lu\n", memory);
    for (i = 0; i < 64; i++) {
        mask = 1UL << i;
        if ((mask & memory) != 0) {
            bit[i] = 1;
        }
        else  {
            bit[i] = 0;
        }
    }
    int indice_spell;
    for (i = 0; i < 64; i++) {
        if (bit[i] == 0)
            continue;
        if (bit[i + 1] == 0)
            continue;
        if (bit[i + 2] == 0)
            continue;
        if (bit[i + 3] == 0)
            continue;
        if (bit[i + 4] == 0)
            continue;
        
        indice_spell = i+5;
        //printf("%d", indice_spell);
        break;
    }
    //printf("\n");
    //printf("%d", indice_spell);
    //printf("\n");


    res = (memory >> (indice_spell));
   
    //printf("%d\n", res);

    
    return res;
}


uint16_t find_key(uint64_t memory)
{
    /*
     * The key is 16 bits and they are in the memory exactly before 3
     * consecutive bits of 1:
     *
     *                high                                           low
     *                     [][][][1][1][1][x][x]...[x][x][]...[][][]
     *                                    |----16bits---|
     *                                           Key
     * Steps:
     * - find 3 consecutive bits of 1
     * - the PREVIOUS 16 bits == key
     */

    uint16_t res = -1;
    


    /* TODO */
    //siftare dreapta =>scap de ce e dupa sirul de 1(3) , inclusiv sirul
    //si recuperare numar siftare inapoi cu cat ne am dus in fata
   

    uint64_t mask;
    uint8_t i;
    int bit[64] = { 0 };
    //printf("%lu\n", memory);
    for (i = 0; i < 64; i++) {
        mask = 1UL << i;
        if ((mask & memory) != 0) {
            bit[i] = 1;
        }
        else {
            bit[i] = 0;
        }
        //printf("%d", bit[i]);
    }
    //printf("\n");
    int indice_spell;
    for (i = 0; i < 64; i++) {
        if (bit[i] == 0)
            continue;
        else if (bit[i + 1] == 0)
            continue;
        else if (bit[i + 2] == 0)
            continue;

        indice_spell = i;
        break;
    }
   

    res = memory >> (indice_spell - 16) ;


    //printf("%d\n", res);

    return res;
}
uint16_t decrypt_spell(uint16_t spell, uint16_t key)
{
    
    /*
     * Find the spell knowing that
     * spell_encrypted = spell_plaintext ^ key
     */

    return spell^key;
}


/* Task 2 - Sword Play */

uint32_t choose_sword(uint16_t enemy)
{
    /*
     * Help Geralt construct a sword that will give him an advantage in battle.
     * The steps we will follow:
     * - choose the corect sword
     * - brand the sword with the correct runes such that the equation
     * for that specific enemy type is true
     *
     * How does the sword look (Sword template):
     *  [][][][] [0][0][0]...[0][0][0] [][][][][][][][][][][][][][][][]
     *  -------- --------------------- --------------------------------
     *     Type    Does not matter      The "Value" such that the equation
     *                               from 2 holds depending on the enemy type
     *    4 bits      12 bits                     16 bits
     *
     * 1. Type of the sword:
     * - 1001 - Silver Sword - for monsters
     * - 0110 - Steel Sword - for humans
     *
     *  If the number of active bits from variable "enemy" is even == Monster
     *  else == Human
     *
     * 2.
     * Monster Equation:
     *    Value ^ (Enemy & (1 - Enemy)) = 0
     *
     * Human Equation:
     *    Value + Enemy = 0
     */
    uint32_t res = -1;
    uint16_t numaratoare = enemy;
    uint16_t aux;
    int c = 0;//nr de biti de 1
    while (numaratoare != 0) {
        c += numaratoare % 2;
        numaratoare = numaratoare / 2;
    }
    if (c % 2 == 0) {
        res = 9 << 28;
        aux = enemy & (1 - enemy);
        res += aux;

    }
    else {
        res = 6 << 28;
        aux = -enemy;
        res += aux;
    }
    
 
    /* TODO */

    return res;
}


/* Task 3 - The Witcher Trials */

uint32_t trial_of_the_grasses(uint16_t cocktail)
{
    /*
     * To become a witcher one must survive a cocktail of different
     * herbs. The body should generate the correct antibodies to
     * neutralize the given cocktail.
     *
     *
     * The antibodies need to respect the following properties:
     *   (antibodies_high & cocktail) ^ (antibodies_low | cocktail) = 0
     *   antibodies_low & antibodies_high = 0
     *   antibodies_low | antibodies_high = cocktail
     *
     * Where:
     *  [][][]...[][][] | [][][]...[][][]
     *  ---------------   ---------------
     *  antibodies_high    antibodies_low
     *      16 bits           16 bits
     *      -------------------------
     *              antibodies
     */

    uint32_t res = -1;

/* TODO */

uint16_t anti_high, anti_low;
uint32_t anti;
uint16_t copie_cocktail;
uint16_t copie_anti_high, copie_anti_low;

copie_cocktail = cocktail;

copie_anti_high = copie_cocktail;
anti_high = copie_anti_high;

copie_anti_low = copie_anti_high - cocktail;
anti_low = copie_anti_low;



anti = (anti_high << 16) + anti_low;
res = anti;
/*printf("%d\n", copie_cocktail);
printf("%d\n", cocktail);
printf("%d\n", anti_low);
printf("%d\n", anti_high);
printf("%d\n\n", anti);*/
return res;
}


uint8_t trial_of_forrest_eyes(uint64_t map)
{
    /*
     * For the next trail, the candidate is tied up and blindfolded.
     * They are also taken to a forest and they should return until
     * the next morning.
     *
     * The candidate knows that there are 4 possibilities for the forest:
     * Brokilon, Hindar, Wolven Glade and Caed Dhu.
     *
     * The candidate also knows those forests by heart, but first you
     * need to identify the forest.
     *
     * The characteristics for 3 of the forests are as follows:
     * - Brokilon - has ONLY groups of 4 trees (or a forest without any tree)
     *   Ex: a group of 4 trees: "...00111100..."
     * - Hindar - has ONLY 2 trees in the MIDDLE
     * - Wolven Glade - FULL of trees
     *
     * The "map" variable encodes the following information:
     * - 1 tree
     * - 0 patch of grass
     *
     * You should put in the "res" variable the index for the identified
     * forrest.
     * - Brokilon - index 0
     * - Hindar - index 1
     * - Wolven Glade - index 2
     * - Caed Dhu - index 3
     */

     /* TODO */

    uint8_t res, k=0;
  

    if (map == 3UL << 31) {
        return (uint8_t)1;
    }

    if (map == 0UL - 1) {
        return (uint8_t)2;
    }

    while (map != 0) {
        if (map % 2 == 1) {
            k++;
        }
        else {
            if (k != 0 && k != 4) {
                return (uint8_t)3;
            }
            else
                k = 0;
        }
        map = map / 2;
    }

    if (k != 4 && k != 0) {
        return (uint8_t)3;
    }

    res = 0;


    return res;

    //return (uint8_t)0;
}


uint8_t trial_of_the_dreams(uint32_t map)
{
    /*
     * For this final trial, the candidates go into a trance and when
     * they woke up they would be a fully fledged witcher.
     *
     * For this task, you need to help the witcher find the number
     * of steps that would take the candidate from the dream realm to
     * the real world.
     *
     * The "map" variable would have only 2 bits of 1:
     * - candidate location
     * - portal location
     *
     * You should put in the "res" variable the distance from the
     * candidate position to the portal.
     *
     *  Ex:
     *  [0][0][0][0][0][0]....[1][0][0][0][0][1][0]....[0][0][0]
     *
     *  res = 5
     */

    uint8_t res = -1;

    uint32_t map_copy, mask;
    map_copy = map;
    int bit[32] = { 0 };
    int i;
    uint8_t distance=0;

    for (i = 0; i < 32; i++) {
        mask = 1 << i;
        if ((map_copy & mask) != 0) {
            bit[i] = 1;
        }
        else
            bit[i] = 0;
        //printf("%d", bit[i]);
    }
    //printf("\n");
    for (i = 0; i < 32; i++) {
        if (bit[i] == 1)
            distance = i - distance;
        else
            continue;
        
    }

    //printf("%d", distance);
    /* TODO */
    res = distance;
    return res;
}

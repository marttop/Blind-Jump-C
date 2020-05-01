/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_sounds
*/

#include "rpg.h"

void init_soundbuffers(all_t *s_all)
{
    s_all->s_sounds.blast_b =
    sfSoundBuffer_createFromFile("sounds/blast1.ogg");
    s_all->s_sounds.hit_b =
    sfSoundBuffer_createFromFile("sounds/bite-small.wav");
    s_all->s_sounds.creak_b =
    sfSoundBuffer_createFromFile("sounds/creak.ogg");
    s_all->s_sounds.laser_b =
    sfSoundBuffer_createFromFile("sounds/laser.ogg");
    s_all->s_sounds.step1_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt1.ogg");
    s_all->s_sounds.step2_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt2.ogg");
    s_all->s_sounds.step3_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt3.ogg");
    s_all->s_sounds.step4_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt4.ogg");
    s_all->s_sounds.step5_b =
    sfSoundBuffer_createFromFile("sounds/footstepDirt5.ogg");
}

void init_sounds(all_t *s_all)
{
    s_all->s_sounds.blast = sfSound_create();
    s_all->s_sounds.creak = sfSound_create();
    s_all->s_sounds.hit = sfSound_create();
    s_all->s_sounds.laser = sfSound_create();
    s_all->s_sounds.step1 = sfSound_create();
    s_all->s_sounds.step2 = sfSound_create();
    s_all->s_sounds.step3 = sfSound_create();
    s_all->s_sounds.step4 = sfSound_create();
    s_all->s_sounds.step5 = sfSound_create();
    init_soundbuffers(s_all);
    sfSound_setBuffer(s_all->s_sounds.blast, s_all->s_sounds.blast_b);
    sfSound_setBuffer(s_all->s_sounds.creak, s_all->s_sounds.creak_b);
    sfSound_setBuffer(s_all->s_sounds.hit, s_all->s_sounds.hit_b);
    sfSound_setBuffer(s_all->s_sounds.laser, s_all->s_sounds.laser_b);
    sfSound_setBuffer(s_all->s_sounds.step1, s_all->s_sounds.step1_b);
    sfSound_setBuffer(s_all->s_sounds.step2, s_all->s_sounds.step2_b);
    sfSound_setBuffer(s_all->s_sounds.step3, s_all->s_sounds.step3_b);
    sfSound_setBuffer(s_all->s_sounds.step4, s_all->s_sounds.step4_b);
    sfSound_setBuffer(s_all->s_sounds.step5, s_all->s_sounds.step5_b);
}
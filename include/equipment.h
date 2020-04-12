/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** equipment.h
*/

#if !defined(EQUIPMENT_H_)
#define EQUIPMENT_H_

void init_equipment(all_t *s_all);
void init_weapon_slot(all_t *s_all);
void draw_weapon_slot(all_t *s_all);
void equip_weapon(all_t *s_all, t_slot *slot);

#endif // EQUIPMENT_H_

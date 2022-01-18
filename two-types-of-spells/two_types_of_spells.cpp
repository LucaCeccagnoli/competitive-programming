#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>

struct Spell{
    int spellType;
    int power;

    // for lookup using only one field
    //Spell(const int s, const int p):
    //    spellType(s),power(p){}

    bool operator<(Spell const& s2) const{
        return this->power < s2.power;
    }
};

int max_damage(std::set<Spell> &fire_spells, std::set<Spell> &lightning_spells)
{
    int total_damage = 0, current_damage;
    bool pertwo = false;
    Spell to_cast;

    while(!lightning_spells.empty())
    {
        // cast weakest lightning spell
        to_cast = *lightning_spells.begin();
        total_damage += to_cast.power;
        lightning_spells.erase(to_cast);
        pertwo = true;

        // while casting lightning spells
        while(!lightning_spells.empty() && to_cast.spellType == 1)
        {
            if(!fire_spells.empty() && (*fire_spells.end()).power > (*lightning_spells.end()).power)
            {
                // cast strongest fire spell
                to_cast = *fire_spells.end();
                current_damage = to_cast.power;
                pertwo = false;
                fire_spells.erase(to_cast);
            }
            else{
                // cast strongest lightning spell
                to_cast = *lightning_spells.end();
                current_damage = to_cast.power;
                pertwo = true;
                lightning_spells.erase(to_cast);
            }
            total_damage += (pertwo) ? current_damage * 2 : current_damage;
        }

        // finish casting fire spells
        while (!fire_spells.empty())
        {
            to_cast = *fire_spells.begin();
            total_damage += to_cast.power;
            fire_spells.erase(to_cast);
            pertwo = false;
        }
    }
    return total_damage;
}

int main(){
    int num_changes, s, p;

    int lightning_spell_count = 0;
    std::set<Spell> fire_spells, lightning_spells, current_set;

    std::cout << "input the number of spell changes" << std::endl;
    std::cin >> num_changes;

    std::cout << "input two integers: \n first:(0 = fire spell, 1 = lightning spell) \n second:(>0 = learn spell of power p, < 0 = forget spell of power p) \n " << std::endl;

    for(int i = 0; i < num_changes; i++){
        std::cin >> s >> p;

        // check spell type
        if(s == 0)
        {
            current_set = fire_spells;
        }
        if( s == 1)
        {
            current_set = lightning_spells;
        }
        else
        {
            std::cout << "invalid spell type" << std::endl;
            i--;
            continue;
        }

        // check power
        if(p > 0)
        {
            Spell new_spell{s, p};

            // new spell must not be already present
            if(current_set.find(new_spell) != current_set.end())
            {
                std::cout << "invalid spell type" << std::endl;
                i--;
                continue;
            }

            // increment lightning counter
            if(new_spell.spellType == 1)
            {
                lightning_spell_count++;
            }

            current_set.insert(new_spell);
        }
        if(p == 0)
        {
            std::cout << "can't create spells with 0 power" << std::endl;
            i--;
            continue;
        }
        else
        {
            // forget a spell
            int p_abs = std::abs(p);
            current_set.erase(Spell{s, p_abs});
        }
        std::cout << "max possible power for this spell list: " << max_damage(fire_spells, lightning_spells) << std::endl;
    }
}
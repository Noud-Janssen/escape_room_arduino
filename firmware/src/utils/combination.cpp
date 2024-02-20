#include "utils/combination.h"

combination::combination()
    : id_index(0), correct_ids({30, 158, 206, 77, 221, 29})
{
}

void combination::add(int id)
{
    if (id_index >= 6)
    {
        return;
    }
    if (id == correct_ids[id_index])
    {
        id_index++;
    }
    else
    {
        id_index = 0;
    }
}

bool combination::is_correct()
{
    return id_index >= 6;
}
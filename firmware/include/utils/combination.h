#ifndef COMBINATION_H
#define COMBINATION_H



class combination
{
public:
    combination();
    ~combination() = default;
public:
    void add(int id);
    bool is_correct();
private:
    int correct_ids[6];
    int id_index;
};


#endif // COMBINATION_H
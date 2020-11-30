#include "hash_table.h"
static int is_prime(size_t n)
{
    if (n <= 1)
        return 0;
    size_t i;
    i = 2;
    while (i < n / 2 + 1)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}
static size_t find_next_prime(size_t n)
{
    size_t next = n;
    while (!is_prime(next++));
    next--;
    assert(is_prime(next));
    return next;
}
hash_table_t * create_hash_table(size_t max_count)
{
    max_count = find_next_prime(max_count);
    hash_table_t *table = malloc(sizeof(hash_table_t));
    if (table)
    {
        table->data = calloc(max_count, sizeof(node_t *));
        table->size = max_count;
    }
    return table;
}
void free_hash_table(hash_table_t **table, void (* free_elem)(void *val))
{
    for (size_t i = 0; i < (*table)->size; i++)
        free_list(&((*table)->data[i]), free_elem);
    free((*table)->data);
    free(*table);
    *table = NULL;
}
size_t hash_func(elem_t *elem, hash_table_t *table)
{
    size_t key = get_key(elem);
    return key % table->size;
}
void read_hash_table(char *filename, hash_table_t *table, void *(*reader)(FILE *f), stat_values_t *stat)
{
    FILE *f = fopen(filename, "r");
    elem_t *el;
    while ((el = reader(f)) != NULL)
    {
        insert_hash_table_elem(table, el);
        stat->elems_count++;
    }
    fclose(f);
}
void print_hash_table(FILE *f, hash_table_t *table, void print_elem(FILE *f, const void *elem))
{
    for (size_t i = 0; i < table->size; i++)
        if (table->data[i] != NULL)
        {
            printf("index: %zu\nvalues in list: ", i);
            print_list(f, table->data[i], print_elem);
            printf("\n");
        }
}
void delete_hash_table_elem(hash_table_t *table, elem_t *elem, void (* free_elem)(void *val), int (* comp)(const void *lhs, const void *rhs), stat_values_t *stat)
{
    elem_t *del_elem;
    size_t ind = hash_func(elem, table);
    if (table->data[ind] != NULL)
    {
        del_elem = find_and_delete(&table->data[ind], elem, comp, &stat->comp_count);
        free_elem(del_elem);
//        node_t *node = find(table->data[ind], elem, comp, comp_count);
//        if (node != NULL)
//        {
//            del_elem = delete_node(&table->data[ind], &node);
//            free_elem(del_elem);
//        }
    }
}
void insert_hash_table_elem(hash_table_t *table, elem_t *value)
{
    size_t ind = hash_func(value, table);
    node_t node;
    node.data = value;
//    node_t *n = find(&(table->data[ind], value, comp);
//    if (n == NULL)
    push_front(&(table->data[ind]), &node);
}

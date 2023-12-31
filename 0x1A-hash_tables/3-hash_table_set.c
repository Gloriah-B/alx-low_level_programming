#include "hash_tables.h"

/**
 * create_node - creates a new hash node
 * @key: key to add the element
 * @value: value to add the element
 *
 * Return: newly created node if successful, NULL otherwise
 */
static hash_node_t *create_node(const char *key, const char *value) {
    hash_node_t *new_node = calloc(1, sizeof(hash_node_t));
    if (!new_node)
        return NULL;

    new_node->key = strdup(key);
    if (!new_node->key) {
        free(new_node);
        return NULL;
    }

    new_node->value = strdup(value);
    if (!new_node->value) {
        free(new_node->key);
        free(new_node);
        return NULL;
    }

    new_node->next = NULL;
    return new_node;
}

/**
 * update_or_create_node - updates or creates a node in the hash table
 * @ht: pointer to hash table
 * @index: index to add the element
 * @key: key to add the element
 * @value: value to add the element
 *
 * Return: 1 if successful, 0 otherwise
 */
static int update_or_create_node(hash_table_t *ht, unsigned long int index, const char *key, const char *value) 
{
	hash_node_t *bucket = ht->array[index];

    while (bucket) {
        if (!strcmp(key, bucket->key)) {
            free(bucket->value);
            bucket->value = strdup(value);
            if (!bucket->value)
                return 0;
            return 1;
        }
        bucket = bucket->next;
    }

    hash_node_t *new_node = create_node(key, value);
    if (!new_node)
        return 0;

    new_node->next = ht->array[index];
    ht->array[index] = new_node;
    return 1;
}

/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: pointer to hash table
 * @key: key to add the element
 * @value: value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value) {
    unsigned long int index = 0;

    if (!ht || !key || !*key || !value)
        return 0;

    index = key_index((const unsigned char *)key, ht->size);

    if (!ht->array[index]) {
        hash_node_t *new_node = create_node(key, value);
        if (!new_node)
            return 0;

        ht->array[index] = new_node;
        return 1;
    }

    return update_or_create_node(ht, index, key, value);
}

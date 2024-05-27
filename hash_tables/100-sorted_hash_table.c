#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#define KEY_INDEX(k, ht) (hash_djb2((const unsigned char *)k) % ht->size)

/**
 * shash_table_create - .
 * @size: .
 * Return: .
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_table = NULL;

	if (!size)
		return (NULL);
	hash_table = malloc(sizeof(shash_table_t));
	if (!hash_table)
		return (NULL);
	hash_table->size = size;
	hash_table->array = calloc(size, sizeof(shash_node_t *) * size);
	if (!hash_table->array)
		return (NULL);
	hash_table->shead = NULL;
	hash_table->stail = NULL;
	return (hash_table);
}


/**
 * shash_table_set - adds element to sorted hash table
 * @ht: .
 * @key: .
 * @value: .
 * Return: .
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long index = 0;
	shash_node_t *add = NULL, *tmp = NULL;

	if (!ht || !key)
		return (0);
	if (!value)
		value = "";
	index = KEY_INDEX(key, ht);
	for (tmp = ht->array[index]; tmp; tmp = tmp->next)
		if (!strcmp(key, tmp->key))
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
	add = malloc(sizeof(shash_node_t));
	if (!add)
		return (0);
	add->key = strdup(key);
	add->value = strdup(value);
	add->next = ht->array[index];
	ht->array[index] = add;
	if (!ht->shead)
	{
		add->snext = NULL;
		add->sprev = NULL;
		ht->shead = add;
		ht->stail = add;
		return (1);
	}
	else if (strcmp(key, ht->shead->key) < 0)
	{
		add->sprev = NULL;
		add->snext = ht->shead;
		ht->shead->sprev = add;
		ht->shead = add;
		return (1);
	}
	for (tmp = ht->shead; tmp->snext && strcmp(key, tmp->snext->key) > 0;)
		tmp = tmp->snext;
	add->sprev = tmp;
	add->snext = tmp->snext;
	if (!tmp->snext)
		ht->stail = add;
	else
		tmp->snext->sprev = add;
	tmp->snext = add;
	return (1);
}

/**
 * shash_table_get - .
 * @ht: .
 * @key: .
 * Return: .
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *got = NULL;
	unsigned long index = 0;

	if (!ht || !key)
		return (NULL);
	index = KEY_INDEX(key, ht);
	if (!ht->array[index])
		return (NULL);
	for (got = ht->array[index]; got; got = got->next)
		if (!strcmp(key, got->key))
			return (got->value);
	return (NULL);
}

/**
 * shash_table_print - .
 * @ht: .
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *print = NULL;

	if (!ht)
		return;
	putchar('{');
	for (print = ht->shead; print; print = print->snext)
		printf("'%s': '%s'%s",
			print->key, print->value,
			print->snext ? ", " : "");
	putchar('}');
	putchar('\n');
}

/**
 * shash_table_print_rev - .
 * @ht: .
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *print = NULL;

	if (!ht)
		return;
	putchar('{');
	for (print = ht->stail; print; print = print->sprev)
		printf("'%s': '%s'%s",
			print->key, print->value,
			print->sprev ? ", " : "");
	putchar('}');
	putchar('\n');
}

/**
 * shash_table_delete - .
 * @ht: .
*/
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *delete = NULL;

	if (!ht)
		return;
	for (delete = ht->shead; delete; delete = ht->shead)
	{
		ht->shead = ht->shead->snext;
		free(delete->key);
		free(delete->value);
		free(delete);
	}
	free(ht->array);
	ht->array = NULL;
	free(ht);
}

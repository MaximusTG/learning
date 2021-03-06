#ifndef HASHTABLE_H
#define HASHTABLE_H

enum HASHTABLE_ERRORS {
    ERR_HASHTABLE_BROKEN = -100,
    ERR_HASHTABLE_DATA_LIST_BROKEN,
    ERR_HASHTABLE_NULL_DATA,
    ERR_HASHTABLE_TABLE_SIZE_BROKEN,
    ERR_HASHTABLE_ELEM_COUNT_BROKEN,
    ERR_HASHTABLE_HASH_FUNCTION_BROKEN,
    ERR_HASHTABLE_DATA_NOT_EXIST,
};

extern const int TEST_TABLE_SIZE;
extern const int TEST_ELEM_COUNT;

struct hashtable {
	int (*hash_function)(struct user_data*);
	struct list **data;
	int table_size;
	int elem_count;
};

struct hashtable *hashtable_construct(int table_size,
                                      int (*hash_function)(struct user_data*));
int hashtable_destruct(struct hashtable *self);
int hashtable_ok(struct hashtable *self);
int hashtable_dump(struct hashtable *self);

int hashtable_size(struct hashtable *self);
int hashtable_table_size(struct hashtable *self);
int hashtable_empty(struct hashtable *self);

int hashtable_hash(struct hashtable *self, struct user_data *data);

int hashtable_insert(struct hashtable *self, struct user_data *data);
int hashtable_erase(struct hashtable *self, struct user_data *data);
int hashtable_clear(struct hashtable *self);

struct list_node *_hashtable_find_node(struct hashtable *self,
                                       struct user_data *data_to_find);
struct user_data *hashtable_find(struct hashtable *self,
                                 struct user_data *data_to_find);
int hashtable_contains(struct hashtable *self, struct user_data *data_to_find);

int hashtable_standard_hash_function(struct user_data *data);

struct hashtable *hashtable_generate();

int hashtable_test_all();
int hashtable_test_ConstructDestruct();
int hashtable_test_Ok();
int hashtable_test_SizeTablesizeEmptyClear();
int hashtable_test_Hash();
int hashtable_test_InsertErase();
int hashtable_test_Contains();

struct user_data *hashtable_max_value_elem(struct hashtable *self);
int hashtable_count_most_used_words(const char *file_name, int top_words_count);

#endif  // HASHTABLE_H

#ifndef GENERAL_H
#define GENERAL_H

#define ERR_RETURN(err_code) \
    do { \
        printf("ERROR [%s]:\n", #err_code); \
		printf("file [%s],\n", __FILE__); \
		printf("function [%s],\n", __FUNCTION__); \
		printf("line [%d]\n", __LINE__); \
        return err_code; \
    } while (0);


#define ASSERT_EQ(first, second) \
	do { \
		if (first != second) { \
			printf("ASSERTION FAILED\n"); \
			exit(EXIT_SUCCESS); \
		} \
	} while (0); \

#define EXPECT_EQ(first, second)\
	do { \
		if (first != second) { \
			printf("EXPECTATION ERROR\n"); \
		} \
	} while (0); \

#define ASSERT_CMP_EQ(first, second, comparator) \
	do { \
		if (comparator(first, second) != TRUE) { \
			printf("ASSERTION FAILED\n"); \
			exit(EXIT_SUCCESS); \
		} \
	} while (0); \

#define EXPECT_CMP_EQ(first, second, comparator) \
	do { \
		if (comparator(first, second) != TRUE) { \
			printf("EXPECTATION ERROR\n"); \
		} \
	} while (0); \

enum GENERAL_ERRORS {
	ERR_ARG1 = -10,
	ERR_ARG2,
	ERR_ARG3,
	ERR_NULL_OBJ,
	ERR_STRING_NOT_CREATED,
	ERR_FILE_NOT_EXIST
};

extern const int POISON_INT;
extern const int TRUE;
extern const int FALSE;
extern const int MAX_MEMORY_ALLOCATION_ATTEMPTS;
extern const int MAX_RANDOM_STRING_LENGTH;

extern const int ORD_a;
extern const int ORD_z;
extern const int ORD_A;
extern const int ORD_Z;
extern const int ORD_0;
extern const int ORD_9;

extern const int TEST_ITER_COUNT;

extern const int SMALL_BUFFER_LENGTH;

int randint(int min, int max);
int randstr(int len, char **string_pointer);

int normalize_string(char **string, int to_free, int full_string_len);
int get_word(char *string, int start_index, char **word);
int string_to_lower(char **string, int to_free, int full_string_len);
int empty_string(char *string);

int delete_character(char *string, int pos);
int delete_first_character(char *string);
int delete_last_character(char *string);

void *many_attempts_calloc(int elem_count, int elem_size, int attempt_count);

#endif  // GENERAL_H

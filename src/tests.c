/**
 * Student Name: Zhanyi Chen
 * Semester: 25Fall
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

int test_swap_two(){
    printf("2. test_swap_two()\n");
    int a = 10;
    int b = 20;

    swap(&a,&b);
    if(a == 20 && b == 10) {
        return 1;
    }
    return 0;
}

/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib_one() {
    printf("3. test_create_array_of_ints_fib_on2()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1,1,2,3,5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note expected does not need freed.. why is that?
    // everything matched
    return 1;
}

int test_create_array_of_ints_fib_two() {
    printf("4. test_create_array_of_ints_fib_two()\n");
    int* arr = create_array_of_ints_fib(2);
    int expected[] = {1,1};
    for (int i = 0; i < 2; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); 
    return 1;
}
int test_create_array_of_ints_fib_three() {
    printf("5. test_create_array_of_ints_fib_three()\n");
    int* arr = create_array_of_ints_fib(0);
    if(arr != NULL){
        free(arr);
        return 0;
    }
    free(arr); 
    return 1;
}

int test_reverse_array_one(){
    printf("6. test_reverse_array_one()\n");
    int array[4] = {1, 3, 5, 7};
    int expected[4] = {7,5,3,1};
    reverse_array(array, 4);
    for(int i = 0; i < 4; i++) {
        if (array[i] != expected[i]){
            return 0;
        }
    }
    return 1;
}
int test_reverse_array_two(){
    printf("7. test_reverse_array_two()\n");
    int array[1] = {1};
    int expected[1] = {1};
    reverse_array(array, 1);
    for(int i = 0; i < 1; i++) {
        if (array[i] != expected[i]){
            return 0;
        }
    }
    return 1;
}

int test_double_array_size_one(){
    printf("8. test_double_array_size_one()\n");
    int array[2] = {1, 2};
    int expected[4] = {1,2,0,0};
    int* actual = double_array_size(array,2);
    for(int i = 0; i < 4; i++){
        if(actual[i] != expected[i]){
            free(actual);
            return 0;
        }
    }
    free(actual);
    return 1;
}
int test_double_array_size_two(){
    printf("9. test_double_array_size_two()\n");
    int array[1] = {0};
    int expected[2] = {0,0};
    int* actual = double_array_size(array,1);
    for(int i = 0; i < 2; i++){
        if(actual[i] != expected[i]){
            free(actual);
            return 0;
        }
    }
    free(actual);
    return 1;
}

int test_copy_array_start_end_loop_one(){
    printf("10. test_copy_array_start_end_loop_one()\n");
    int new_size =0;
    int array[5] = {1, 2, 3, 4, 5};
    int *new_array = copy_array_start_end_loop(array,5,1,3,&new_size);
    int expected[3] = {2,3,4};
    for(int i = 0; i < 3; i++){
        if(new_array[i] != expected[i]){
            free(new_array);
            return 0;
        }
    }
    free(new_array);
    return 1;
}
int test_copy_array_start_end_loop_two(){
    printf("11. test_copy_array_start_end_loop_two()\n");
    int new_size = 0;
    int array[5] = {1, 2, 3, 4, 5};
    int *new_array = copy_array_start_end_loop(array,5,3,1,&new_size);
    int expected[4] = {4,5,1,2};
    for(int i = 0; i < 4; i++){
        if(new_array[i] != expected[i]){
            free(new_array);
            return 0;
        }
    }
    free(new_array);
    return 1;
}
int test_copy_array_start_end_loop_three(){
    printf("12. test_copy_array_start_end_loop_three()\n");
    int new_size = 0;
    int array[5] = {1, 2, 3, 4, 5};
    int *new_array = copy_array_start_end_loop(array,5,3,3,&new_size);
    int expected[1] = {4};
    for(int i = 0; i < 1; i++){
        if(new_array[i] != expected[i]){
            free(new_array);
            return 0;
        }
    }
    free(new_array);
    return 1;
}

int test_create_point_one(){
    printf("13. test_create_point_one()\n");
    Point p1 = {1,2};
    Point *p2 = create_point(1,2);
    if(p1.x == p2 ->x && p1.y == p2 ->y){
        free(p2);
        return 1;
    }
    free(p2);
    return 0;
}
int test_create_point_two(){
    printf("14. test_create_point_two()\n");
    Point p1 = {0,0};
    Point *p2 = create_point(0,0);
    if(p1.x == p2 ->x && p1.y == p2 ->y){
        free(p2);
        return 1;
    }
    free(p2);
    return 0;
}

int test_create_polygon_one(){
    printf("15. test_create_polygon_one()\n");
    Polygon *actual = create_polygon(5);
    if(actual->size!=5){
        free_polygon(actual);
        return 0;
    }
    free_polygon(actual);
    return 1;
}
int test_create_polygon_two(){
    printf("16. test_create_polygon_two()\n");
    Polygon *actual = create_polygon(0);
    if(actual->size!=0){
        free_polygon(actual);
        return 0;
    }
    free_polygon(actual);
    return 1;
}

int test_create_rectangle_one(){
    printf("17. test_create_rectangle_one\n");
    Polygon *rec = create_rectangle(3,4);
    if(rec->size != 4){
        return 0;
    }
    Point **points = rec->points;
    if(points[0]->x == 0
    && points[0]->y ==0
    &&points[1]->x == 3
    && points[1]->y == 0
    &&points[2]->x == 3
    && points[2]->y ==4
    &&points[3]->x == 0
    && points[3]->y ==4){
        print_polygon(rec);
        free_polygon(rec);
        return 1;
    }
    free_polygon(rec);
    return 0;

}
int test_create_rectangle_two(){
    printf("18. test_create_rectangle_two\n");
    Polygon *rec = create_rectangle(0,3);
    if(rec){
        return 0;
    }
    return 1;

}
int test_create_triangle_one(){
    printf("19. test_create_triangle_one\n");
    Polygon *tri = create_triangle(3,4);
    if(tri->size != 3){
        return 0;
    }
    Point **points = tri->points;
    if(points[0]->x == 0
    && points[0]->y ==0
    &&points[1]->x == 3
    && points[1]->y == 0
    &&points[2]->x == 3
    && points[2]->y ==4)
    {
        print_polygon(tri);
        free_polygon(tri);
        return 1;
    }
    free_polygon(tri);
    return 0;

}
int test_create_triangle_two(){
    printf("20. test_create_triangle_two\n");
    Polygon *tri = create_rectangle(0,3);
    if(tri){
        return 0;
    }
    return 1;
    
}

int test_calculate_polygon_area_one(){
    printf("21. test_calculate_polygon_area_one\n");

    Polygon *tri = create_triangle(3,4);
    int area = calculate_polygon_area(tri);
    if (area == 6.0){
        return 1;
    }
    return 0;

}
int test_calculate_polygon_area_two(){
    printf("22. test_calculate_polygon_area_two\n");

    Polygon *rec = create_rectangle(3,4);
    int area = calculate_polygon_area(rec);
    if (area == 12.0){
        return 1;
    }
    return 0;

}
int test_calculate_polygon_area_three(){
    printf("23. test_calculate_polygon_area_three\n");

    int area = calculate_polygon_area(NULL);
    if (area == 0){
        return 1;
    }
    return 0;

}

// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_swap_two,
        test_create_array_of_ints_fib_one,
        test_create_array_of_ints_fib_two,
        test_create_array_of_ints_fib_three,
        test_reverse_array_one,
        test_reverse_array_two,
        test_double_array_size_one,
        test_double_array_size_two,
        test_copy_array_start_end_loop_one,
        test_copy_array_start_end_loop_two,
        test_copy_array_start_end_loop_three,
        test_create_point_one,
        test_create_point_two,
        test_create_polygon_one,
        test_create_polygon_two,
        test_create_rectangle_one,
        test_create_rectangle_two,
        test_create_triangle_one,
        test_create_triangle_two,
        test_calculate_polygon_area_one,
        test_calculate_polygon_area_two,
        test_calculate_polygon_area_three,
        
        
       
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i + 1);
        }
    }
    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}

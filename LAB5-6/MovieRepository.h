//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_MOVIEREPOSITORY_H
#define LAB5_6_MOVIEREPOSITORY_H

#include "DynamicArray.h"
#include "Movie.h"
#include "STLVector.h"

class MovieRepository {
private:
    //DynamicArray<Movie> movies;
    STLVector<Movie> movies;

public:

    // Constructors and Destructors
    MovieRepository();
    ~MovieRepository();

    //Getters
    DynamicArray<Movie> & getMovies();
    DynamicArray<Movie> getByGenre(string genre);

    //Functionality
    void add(Movie movie);
    void del(Movie movie);
    void update(string title, Movie movie);

    //ForIterators
    Movie * begin();
    Movie * end();


};


#endif //LAB5_6_MOVIEREPOSITORY_H

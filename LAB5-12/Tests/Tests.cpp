//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#include <assert.h>
#include "Tests.h"
#include "../Controller/MovieController.h"
#include "../Others/Exception.h"
#include "../Controller/MovieController.h"
#include "../Repository/MemoryMovieRepository.h"
#include "../Repository/FileMovieRepository.h"
#include "../Repository/MemoryWatchListRepository.h"

#define STL  MemoryMovieRepository<STLVector<Movie>>

Tests::Tests() {
    /*
     * CONSTRUCTOR ... starts the tests
     */

    //Instantiate the controller
    this->movieController = new  MovieController< STL >( new MemoryWatchListRepository() );

    this->testAdminAdd();
    this->testUserAdd();
    this->testUserDel();
    this->testAdminDel();
    this->testAdminUpdate();


}


void Tests::testAdminAdd() {
    this->movieController->add("Sorinium", "Horror", 2017, 10, "https://no");
    assert(this->movieController->getMovieRepository().getMovies().size() == 1 );

    this->movieController->add("Medium", "Action", 2000, 15, "https://yes");
    assert(this->movieController->getMovieRepository().getMovies().size() == 2 );

    this->movieController->add("A", "Action", 300, 45, "https://DA");
    assert(this->movieController->getMovieRepository().getMovies().size() == 3 );

    this->movieController->add("B", "Action", 1950, 65, "https://NU");
    assert(this->movieController->getMovieRepository().getMovies().size() == 4 );

    this->movieController->add("C", "Action", 1980, 75, "https://GIGI");
    assert(this->movieController->getMovieRepository().getMovies().size() == 5 );


    try {
        this->movieController->add("C", "Action", 1980, 75, "https://GIGI");
        assert(false);


    } catch(Exception ex) {
       assert(true);
    }

    assert(this->movieController->getMovieRepository().getMovies().size() == 5 );
}

void Tests::testAdminDel() {
    this->movieController->del("A");
    assert(this->movieController->getMovieRepository().getMovies().size() == 4 );

    this->movieController->del("B");
    assert(this->movieController->getMovieRepository().getMovies().size() == 3 );

    this->movieController->del("C");
    assert(this->movieController->getMovieRepository().getMovies().size() == 2 );

    try {
        this->movieController->del("C");
        assert(false);


    } catch(Exception ex) {
        assert(true);
    }

}

void Tests::testAdminUpdate() {
    this->movieController->update("Medium", "Mediums", "Action", 2000, 15, "https://yes");

    try {
        this->movieController->del("Medium");
        assert(false);


    } catch(Exception ex) {
        assert(true);
    }

    this->movieController->update("Mediums", "Medium", "Action", 2000, 15, "https://yes");

    try {
        this->movieController->del("Mediums");
        assert(false);


    } catch(Exception ex) {
        assert(true);
    }

    this->movieController->update("Medium", "Medium", "X", 1, 1, "");
    int pos = this->movieController->getMovieRepository().getMovies().find(Movie("Medium"));
    Movie crtMovie = this->movieController->getMovieRepository().getMovies().get(pos);

    assert(crtMovie.getGenre() == "X" && crtMovie.getLikes() == 1 && crtMovie.getYear() == 1);

}

void Tests::testUserAdd() {
    this->movieController->getWatchListRepository()->add(WatchListItem("A"));
    int x = this->movieController->getWatchListRepository()->getWatchList().size();
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 1);

    this->movieController->getWatchListRepository()->add(WatchListItem("B"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 2);

    this->movieController->getWatchListRepository()->add(WatchListItem("C"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 3);

    this->movieController->getWatchListRepository()->add(WatchListItem("D"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 4);

    this->movieController->getWatchListRepository()->add(WatchListItem("E"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 5);

    try {
        this->movieController->getWatchListRepository()->add(WatchListItem("E"));
        assert(false);

    } catch(Exception ex) {
        assert(true);
    }

}

void Tests::testUserDel() {
    this->movieController->getWatchListRepository()->del(WatchListItem("E"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 4);

    this->movieController->getWatchListRepository()->del(WatchListItem("D"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 3);

    this->movieController->getWatchListRepository()->del(WatchListItem("C"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 2);

    this->movieController->getWatchListRepository()->del(WatchListItem("B"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 1);

    this->movieController->getWatchListRepository()->del(WatchListItem("A"));
    assert(this->movieController->getWatchListRepository()->getWatchList().size() == 0);

    try {
        this->movieController->getWatchListRepository()->del(WatchListItem("A"));
        assert(false);

    } catch(Exception ex) {
        assert(true);
    }

}

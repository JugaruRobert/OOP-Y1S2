//
// Created by Sorin Sebastian Mircea on 22/03/2017.
//

#ifndef LAB5_6_MOVIECONTROLLER_H
#define LAB5_6_MOVIECONTROLLER_H
#include "../Repository/MovieRepository.h"
#include "../Model/WatchListItem.h"
#include "../Repository/IWatchListRepository.h"
#include "../Repository/CSVWatchListRepository.h"
#include "../Repository/HTMLWatchListRepository.h"
#include "../UndoRedo/UndoRedo.h"
#include "../UndoRedo/UndoRedoAdd.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

#define CONTAINER STLVector<Movie>
template<class TRepo>
class MovieController {
private:
    TRepo movieRepository = TRepo();
    IWatchListRepository* watchListRepository;

public:
    vector< shared_ptr<UndoRedo<TRepo> > > undoList;
    vector< shared_ptr<UndoRedo<TRepo> > > redoList;

public:
    // Constructors and Destructors
    MovieController();
    MovieController(IWatchListRepository* watchListRepo);
    ~MovieController();

    //Getters
    TRepo & getMovieRepository();
    IWatchListRepository* getWatchListRepository();
    Movie getByGenreByStep(string genre, int pos);

    //Setters
    void setWatchListRepository(IWatchListRepository *watchListRepository);

    //Functionality
    void add(string title, string genre, int year, int likes, string trailer);
    void del(string title);
    void update(string titleOld, string titleNew, string genreNew, int yearNew, int likesNew, string trailerNew);
    void incrementLikes(string title);
};


#endif //LAB5_6_MOVIECONTROLLER_H

#ifndef MOVIE__H__
#define MOVIE__H__

# include <string>

# include <vector>

# include <sstream>

struct Movie
{
    std::string name;

    std::string id;

    int timestamp;

    std::vector<std::string> categories;

    std::string director_name;

    std::vector<std::string> actors_ids;

    double rating;

    double votes;

    double sum;

    Movie(std::string movie_name, std::string movie_id, int timestamp,
          std::vector<std::string> categories, std::string director_name,
          std::vector<std::string> actor_ids)
    {
        this->name = movie_name;

        this->id = movie_id;

        this->timestamp = timestamp;

        this->categories = categories;

        this->director_name = director_name;

        this->actors_ids = actor_ids;
    }

    void add_rating(double new_rating)
    {
        this->votes += 1;

        this->sum += new_rating;

        this->rating = this->sum / this->votes;
    }

    void update_rating(double new_rating, double old_rating)
    {
        this->sum -= old_rating;

        this->sum += new_rating;

        this->rating = this->sum / this->votes;
    }

    void remove_rating(double old_rating)
    {
        this->votes -= 1;

        this->sum -= old_rating;

        this->rating = this->sum / this->votes;
    }

    std::string get_rating()
    {
        this->rating = round(this->rating * 100) / 100;

        std::ostringstream aux;

        aux << this->rating;

        return aux.str();
    }
};

#endif  // MOVIE__H__

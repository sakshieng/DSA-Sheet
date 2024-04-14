import './App.css';
import React , {useState, useEffect} from 'react';
import axios from "axios";
import SearchIcon from "./search.svg";
import Card from './Card';
// import fetchMarvelCharacters from './dataFetching';

  
const API_KEY = process.env.REACT_APP_PUBLIC_API_KEY;
const HASH_KEY = process.env.REACT_APP_HASH_API_KEY;
const URL = `http://gateway.marvel.com/v1/public/comics/1158/characters?ts=This%20is%20the%20data%20to%20hash.&apikey=${API_KEY}&hash=${HASH_KEY}`;

console.log(URL);
const API= axios.create({
  baseURL: URL
})


async function fetchMarvelCharacters() {
  try {
    const response = await API.get();
    console.log(URL);
    if (response.status !== 200) {
      throw new Error(`Network response was not ok: ${response.status}`);
    }

    const jsonData = response.data;
    console.log(jsonData);
    // Check if data and results exist before mapping
    const characters = jsonData.data.results.map((character) => ({
        name: character.name,
        thumbnail: `${character.thumbnail.path}.${character.thumbnail.extension}`,
        comics_available: character.comics.available,
        series_available: character.series.available,
        stories_available: character.stories.available
      }));

    return characters;

  } catch (error) {
    console.error('An error occurred:', error);
  }
  // console.log(URL);
}

function App() {
  const [characters, setCharacters] = useState([]);
  const [searchTerm, setSearchTerm] = useState("");
  const [searchResults, setSearchResults] = useState([]);
  const [isLoading, setIsLoading] = useState(true);

  useEffect(() => {
    const fetchCharacters = async () => {
      const characters = await fetchMarvelCharacters();
      setCharacters(characters);
      setIsLoading(false);
    };
    fetchCharacters();
  }, []);

  useEffect(() => {
    const results = characters.filter((character) =>
      character.name.toLowerCase().includes(searchTerm)
    );
    setSearchResults(results);
  }, [searchTerm, characters]);

  const handleChange = (event) => {
    setSearchTerm(event.target.value);
  };

  return (
    <div className="App">
      <div className="container">
        
        <div className="header">
          <h1>Marvel Characters</h1>

          <div className="search">
            <img src={SearchIcon} alt="Search Icon" />
            <input
              type="text"
              placeholder="Search"
              value={searchTerm}
              onChange={handleChange}
            />
          </div>
        </div>

        <div className="characters">
          {isLoading ? (
            <p>Loading...</p>
          ) : (
            searchResults.map((character, index) => (
              <Card key={index} character={character} />
            ))
          )}
        </div>

      </div>
    </div>
  );
}

export default App;
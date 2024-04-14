import React from 'react';

const Card = ({ character }) => {
  return (
    <div className="character-card">
      <img src={character.thumbnail} alt={character.name} />
      <h3>{character.name}</h3>
      <p>Comics Available: {character.comics_available}</p>
      <p>Series Available: {character.series_available}</p>
      <p>Stories Available: {character.stories_available}</p>
    </div>
  );
};

export default Card;

import { describe, expect, it } from 'vitest';
import { getRandomDogImage } from '../services/dogService';

const mockedResponse = {
  message: 'https://images.dog.ceo/breeds/terrier-welsh/lucy.jpg',
  status: 'success'
};
import { describe, expect, it, vi } from 'vitest';
import type { Request, Response } from 'express';
import { getDogImage } from '../controllers/dogController';
import { getRandomDogImage } from '../services/dogService';

vi.mock('../services/dogService', () => ({
  getRandomDogImage: vi.fn()
}));

const mockedDogData = {
  imageUrl: 'https://images.dog.ceo/breeds/terrier-welsh/lucy.jpg',
  status: 'success'
};

describe('getDogImage', () => {
  it('should fetch and return a dog image response', async () => {
    vi.mocked(getRandomDogImage).mockResolvedValue(mockedDogData);

    const response = {
      json: vi.fn(),
      status: vi.fn().mockReturnThis()
    } as unknown as Response;

    await getDogImage({} as Request, response);

    expect(response.json).toHaveBeenCalledWith({
      success: true,
      data: mockedDogData
    });
  });
});
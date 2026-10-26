import { describe, expect, it, vi } from 'vitest';
import { getRandomDogImage } from '../services/dogService';

const mockedResponse = {
  message: 'https://images.dog.ceo/breeds/terrier-welsh/lucy.jpg',
  status: 'success'
};

describe('getRandomDogImage', () => {
  it('should fetch and return a dog image response', async () => {
    const fetchMock = vi.fn(() =>
      Promise.resolve({
        ok: true,
        status: 200,
        json: () => Promise.resolve(mockedResponse)
      })
    );

    vi.stubGlobal('fetch', fetchMock);

    const result = await getRandomDogImage();

    expect(result.status).toBe('success');
    expect(result.imageUrl).toMatch(/^https:\/\/images\.dog\.ceo\/.+/);
    expect(fetchMock).toHaveBeenCalledOnce();
  });

  it('should throw an error if the fetch fails', async () => {
    const fetchMock = vi.fn(() =>
      Promise.resolve({
        ok: false,
        status: 500,
        json: () => Promise.resolve({ message: 'Failed to fetch dog image: Dog API returned status 500' })
      })
    );
    vi.stubGlobal('fetch', fetchMock);

    await expect(getRandomDogImage()).rejects.toThrow('Failed to fetch dog image: Dog API returned status 500');
  });
});
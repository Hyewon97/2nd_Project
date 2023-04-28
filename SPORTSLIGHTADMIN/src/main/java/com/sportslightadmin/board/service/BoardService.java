package com.sportslightadmin.board.service;

import java.util.List;

import com.sportslightadmin.board.dto.BoardDTO;
import com.sportslightadmin.board.dto.BoardPageDTO;

public interface BoardService {
	public int countProcess(); 
	public List<BoardDTO> listProcess(BoardPageDTO pv);
	public void insertProcess(BoardDTO dto);
	public BoardDTO contentProcess(int num);
//	public BoardDTO updateSelectProcess(int num);
	public void updateProcess(BoardDTO dto, String urlpath);
	public void deleteProcess(int num, String urlpath);
	public String fileSelectprocess(int num);
}

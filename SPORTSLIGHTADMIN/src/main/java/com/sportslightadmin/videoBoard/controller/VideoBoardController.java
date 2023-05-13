package com.sportslightadmin.videoBoard.controller;

import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

import com.sportslightadmin.videoBoard.dto.VideoBoardPageDTO;
import com.sportslightadmin.videoBoard.service.VideoBoardService;

// 모든 요청 허용
@CrossOrigin("*")

@RestController
public class VideoBoardController {
	
	@Autowired
	private VideoBoardService videoBaordService;
	
	@Autowired
	private VideoBoardPageDTO pdto;
	
	private int currentPage;
	
	public VideoBoardController() {
		
	}
	
	// 한줄 게시판 리스트
	@GetMapping("/admin/videoBoard/list/{videoNum}/{currentPage}")
	public Map<String, Object> listExecute(@PathVariable("currentPage") int currentPage, 
			@PathVariable("videoNum") int videoNum, VideoBoardPageDTO pv) {
		
		// videoNum 값 확인 // 주석
		System.out.println("videoNum:"+videoNum); // 값은 제대로 들어가는거 같은데
		// videoNum 값 확인 // 주석
		System.out.println("currentPage:"+currentPage);
		
		Map<String, Object> map = new HashMap<>();
		System.out.println("pv : " + pv.getCurrentPage()); // currentPage값 출력

		int totalRecord = videoBaordService.countProcess(videoNum);
		// 갯수가 한 개 이상이면 페이징 처리를 해줌
		// countProcess에서는 값이 제대로 들어감
		
		System.out.println("totalRecord : " + totalRecord);
		
		if (totalRecord >= 1) {
			this.currentPage = currentPage; // currentPage에 1 할당

			this.pdto = new VideoBoardPageDTO(this.currentPage, videoNum);
			pdto.setVideoNum(videoNum); // 비디오넘 값 넣어서 던져줌 // 준찬님의 도움  감사

			map.put("aList", videoBaordService.videoBoardListProcess(this.pdto));
			map.put("pv", this.pdto);

		}
		return map;
	}
	
	// 삭제
	@DeleteMapping("admin/videoBoard/list/delete/{videoBoardNum}")
	public void deleteExecute(@PathVariable("videoBoardNum") int videoBoardNum, HttpServletRequest request) {
		videoBaordService.deleteProcess(videoBoardNum);
	}
	
	
}














